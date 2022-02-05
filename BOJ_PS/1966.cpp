#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int comp(int a,int b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	int N, M;
	int* max;
	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> q;
		cin >> N >> M;
		int tempq;
		max = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> tempq;
			q.push(make_pair(i,tempq));
			max[i] = tempq;
		}
		sort(max, max + N,comp);
		int count = 0;
		int maxidx = 0;
		while (count < N) {
			count++;
			while (q.front().second != max[maxidx]) {
				pair<int,int> node = q.front();
				q.push(node);
				q.pop();
			}
			if (q.front().first == M)
				break;
			else {
				q.pop();
				maxidx++;
			}
		}
		cout << count << '\n';
		delete[] max;
	}
	return 0;
}