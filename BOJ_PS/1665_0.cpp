//우선순위 큐에서 메디안을 매번 구하는 문제.
//힙 두개를 관리하여 구현한다.(한 힙은 중간값 이하 값, 다른 힙은 중간값 이후 값)
#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	multiset<int, greater<int>> pq;
	multiset<int, less<int>> pq2;
	multiset<int>::iterator iter;
	int N;
	int input;
	cin >> N;
	for (int T = 0; T < N; T++) {
		cin >> input;
		if (pq.empty()) {
			pq.insert(input);
			cout << input << '\n';
			continue;
		}
		iter = pq.begin();
		if (*iter <= input)
			pq2.insert(input);
		else
			pq.insert(input);

		if (pq.size() > pq2.size() + 1) {
			int tempval = *iter;
			pq.erase(iter);
			pq2.insert(tempval);
		}
		else if (pq.size() < pq2.size()) {
			iter = pq2.begin();
			int tempval = *iter;
			pq2.erase(iter);
			pq.insert(tempval);
		}
		iter = pq.begin();
		cout << *iter << '\n';
	}
	return 0;
}