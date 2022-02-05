#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (1) {
		if (q.size() == 1) {
			cout << q.front() << '\n';
			return 0;
		}
		q.pop();
		if (q.size() == 1) {
			cout << q.front() << '\n';
			return 0;
		}
		int temp = q.front();
		q.push(temp);
		q.pop();
	}
	return 0;
}