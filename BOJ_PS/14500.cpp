#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[500][500];
pair<int, int> tet[19][3] =
{ {{0,1},{0,2},{0,3}},
{{1,0},{2,0},{3,0}},
{{0,1},{1,0},{1,1}},
{{1,0},{2,0},{2,1}},
{{0,1},{0,2},{-1,2}},
{{0,1},{1,1},{2,1}},
{{1,0},{0,1},{0,2}},
{{1,0},{1,1},{2,1}},
{{0,1},{-1,1},{-1,2}},
{{0,1},{0,2},{1,1}},
{{1,0},{2,0},{1,1}},
{{0,1},{0,2},{-1,1}},
{{1,0},{2,0},{1,-1}},
{{0,1},{1,0},{2,0}},
{{1,0},{1,1},{1,2}},
{{0,1},{-1,1},{-2,1}},
{{0,1},{0,2},{1,2}},
{{-1,0},{-1,1},{-2,1}},
{{0,1},{1,1},{1,2}},
};
bool valid(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }
int main()
{
	FAST;
	int y, x, tmp, ans = 0;
	bool flag;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> p[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				tmp = p[i][j],flag = true;
				for (const auto& s : tet[k]) {
					y = i + s.first, x = j + s.second;
					if (valid(y, x))
						tmp += p[y][x];
					else {
						flag = false;
						break;
					}
				}
				if (flag) ans = max(ans, tmp);
			}
		}
	}
	cout << ans;
	return 0;
}