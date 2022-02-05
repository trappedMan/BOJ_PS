#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

typedef struct _edge {
	int src;
	int dest;
} edge;
bool isvisited[200001];
int level[200001];
int maxval;

bool valid(int n) {
	if (n >= 0 && n <= 200000)
		return true;
	else
		return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K, now;
	cin >> N >> K;
	maxval = N > K ? N : K;
	memset(isvisited, false, 200001);
	memset(level, 0, 200001*sizeof(int));
	queue<int> q;
	q.push(N);
	isvisited[N] = true;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now == K)
			break;
		if (valid(now - 1))
			if (!isvisited[now - 1]) {
				isvisited[now - 1] = true;
				level[now - 1] = level[now] + 1;
				q.push(now - 1);
			}
		if (valid(now + 1))
			if (!isvisited[now + 1]) {
				isvisited[now + 1] = true;
				level[now + 1] = level[now] + 1;
				q.push(now + 1);
			}
		if (valid(2 * now))
			if (!isvisited[2 * now]) {
				isvisited[2 * now] = true;
				level[now * 2] = level[now] + 1;
				q.push(2 * now);
			}
	}
	cout << level[now] << '\n';
	return 0;
}