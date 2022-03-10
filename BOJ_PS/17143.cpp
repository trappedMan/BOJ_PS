#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
struct shark {int y, x, s, d, z;};
int r, c, m, ans = 0;
shark water[100][100];
shark newwater[100][100];
void func() {
	for (int i = 0; i < r;i++) {
		for (int j = 0; j < c; j++) {
			if (water[i][j].z) {
				if (water[i][j].d == 1) {
					water[i][j].y -= water[i][j].s;
					if (water[i][j].y < 0) {
						water[i][j].d = 2;
						water[i][j].y *= -1;
					}
					if (water[i][j].y >= r) {
						water[i][j].d = 1;
						water[i][j].y = 2 * r - water[i][j].y - 2;
					}
				}
				else if (water[i][j].d == 2) {
					water[i][j].y += water[i][j].s;
					if (water[i][j].y >= r) {
						water[i][j].d = 1;
						water[i][j].y = 2 * r - water[i][j].y - 2;
					}
					if (water[i][j].y < 0) {
						water[i][j].d = 2;
						water[i][j].y *= -1;
					}
				}
				else if (water[i][j].d == 3) {
					water[i][j].x += water[i][j].s;
					if (water[i][j].x >= c) {
						water[i][j].d = 4;
						water[i][j].x = 2 * c - water[i][j].x - 2;
					}
					if (water[i][j].x < 0) {
						water[i][j].d = 3;
						water[i][j].x *= -1;
					}
				}
				else{
					water[i][j].x -= water[i][j].s;
					if (water[i][j].x < 0) {
						water[i][j].d = 3;
						water[i][j].x *= -1;
					}
					if (water[i][j].x >= c) {
						water[i][j].d = 4;
						water[i][j].x = 2 * c - water[i][j].x - 2;
					}
				}
				if (newwater[water[i][j].y][water[i][j].x].z < water[i][j].z) {
					newwater[water[i][j].y][water[i][j].x] = water[i][j];
				}
				water[i][j] = { 0,0,0,0,0 };
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			water[i][j] = newwater[i][j];
			newwater[i][j] = { 0,0,0,0,0 };
		}
	}
}
int main()
{
	FAST;
	int y, x, s, d, z;
	cin >> r >> c >> m;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			water[i][j] = { 0,0,0,0,0 };
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> y >> x >> s >> d >> z;
		if (d >= 3)
			s %= (2 * c - 2);
		else
			s %= (2 * r - 2);
		water[y-1][x-1] = { y-1,x-1,s,d,z };
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (water[j][i].z) {
				ans += water[j][i].z;
				water[j][i] = { 0,0,0,0,0 };
				break;
			}
		}
		func();
	}
	cout << ans;
	return 0;
}