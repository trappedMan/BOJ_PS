#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct zombie {
	int y;
	int x;
	int dir;
};
pii dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
pii lightdir[8] = { {1,0},{1,1}, {0,1},{-1,1}, {-1,0},{-1,-1}, {0,-1},{1,-1} };
vector<zombie> z;
char grid[15][15];
bool light[15][15];
int n;
string com;
bool flag = true;
bool valid(int y, int x) { return 0 <= y && y < n && 0 <= x && x < n; }
int main()
{
	FAST;
	string str;
	int nowy = 0, nowx = 0, nowdir = 0;
	cin >> n;
	cin >> com;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			grid[i][j] = str[j];
			if (str[j] == 'z' || str[j] == 'Z') {
				z.push_back({ i,j,0 });
			}
		}
	}
	for (int i = 0; i < com.size() && flag; i++) {
		if (com[i] == 'L') {
			nowdir = (nowdir + 1) % 4;
		}
		else if (com[i] == 'R') {
			nowdir - 1 < 0 ? nowdir = 3 : nowdir--;
		}
		else {
			if (valid(nowy + dir[nowdir].first, nowx + dir[nowdir].second)) {
				nowy += dir[nowdir].first; nowx += dir[nowdir].second;
				if (grid[nowy][nowx] == 'S' || grid[nowy][nowx] == 's') {
					light[nowy][nowx] = true;
					for (int d = 0; d < 8; d++) {
						if (valid(nowy + lightdir[d].first, nowx + lightdir[d].second))
							light[nowy + lightdir[d].first][nowx + lightdir[d].second] = true;
					}
				}
			}
		}
		for (auto& zom : z) {
			if (zom.y == nowy && zom.x == nowx && !light[nowy][nowx]) {
				flag = false;
				break;
			}
			if (valid(zom.y + dir[zom.dir].first, zom.x + dir[zom.dir].second)) {
				zom.y += dir[zom.dir].first; zom.x += dir[zom.dir].second;
				if (zom.y == nowy && zom.x == nowx && !light[nowy][nowx]) {
					flag = false;
					break;
				}
			}
			else
				zom.dir = (zom.dir + 2) % 4;
		}
	}
	flag ? (cout << "Phew...") : (cout << "Aaaaaah!");
	return 0;
}