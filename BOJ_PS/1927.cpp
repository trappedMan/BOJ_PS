#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, command;
	priority_queue<int,vector<int>,greater<int>> pq;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (command == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(command);
	}
	return 0;
}