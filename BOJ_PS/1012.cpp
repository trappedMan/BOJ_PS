#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
typedef struct {
	bool isplanted;
	bool isvisited;
} cabbage;

void dfs(cabbage ** land, int x, int y,int N,int M) {
	if (x > 0) {
		if (!land[x - 1][y].isvisited && land[x - 1][y].isplanted) {
			land[x - 1][y].isvisited = 1;
			dfs(land, x - 1, y, N, M);
		}
	}
	if (x < N-1) {
		if (!land[x + 1][y].isvisited && land[x + 1][y].isplanted) {
			land[x + 1][y].isvisited = 1;
			dfs(land, x + 1, y, N, M);
		}
	}
	if (y > 0) {
		if (!land[x][y - 1].isvisited && land[x][y - 1].isplanted) {
			land[x][y - 1].isvisited = 1;
			dfs(land, x, y - 1, N, M);
		}
	}
	if (y < M - 1) {
		if (!land[x][y + 1].isvisited && land[x][y + 1].isplanted) {
			land[x][y + 1].isvisited = 1;
			dfs(land, x, y + 1, N, M);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, M, N, K;
	int x, y;
	cin >> T;
	cabbage** land;
	for (int t = 0; t < T; t++) {
		int count = 0;
		cin >> M >> N >> K;
		land = new cabbage * [N];
		for (int j = 0; j < N; j++) {
			*(land + j) = new cabbage[M];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				land[i][j].isplanted = 0;
				land[i][j].isvisited = 0;
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			land[y][x].isplanted = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!land[i][j].isvisited && land[i][j].isplanted) {
					dfs(land, i, j, N, M);
					count++;
				}
			}
		}
		cout << count << '\n';
		for (int j = 0; j < N; j++) {
			delete[] * (land + j);
		}
		delete[] land;
	}
	return 0;
}