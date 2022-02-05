//key가 같을 때 value 기준으로도 정렬을 해야 한다면 multimap같은걸 쓰기보다 pair을 담는 vector로 선언뒤 정렬하는게 낫다
//pair은 기본적으로 first가 같으면 second로 정렬하도록 되어있다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int start, end;
	int nowend;
	int count = 0;
	vector<pair<int, int>> vecsche;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		vecsche.push_back(make_pair(end, start));
	}
	sort(vecsche.begin(), vecsche.end());
	nowend = -1;
	for (const auto& iter : vecsche) {
		if (iter.second >= nowend) {
			count++;
			nowend = iter.first;
		}
	}
	cout << count << '\n';
	return 0;
}