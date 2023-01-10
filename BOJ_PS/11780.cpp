#define BIG 100000000
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
int dist[100][100];
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = BIG;
			if (i == j)
				dist[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if(dist[a-1][b-1]>c)
			dist[a-1][b-1] = c;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	//Ãâ·Â
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == BIG) {
				cout << 0 << ' ';
				continue;
			}
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

