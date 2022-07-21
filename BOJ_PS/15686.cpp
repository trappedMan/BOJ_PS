#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int n, m, total_minus_m;
int city[50][50];
set<pair<int, int>> s;
int minval = 1e9;

int calc_dist() {
	int accum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (city[i][j] == 1) {
				int tmpminval = 1e9;
				for (const auto& t : s) {
					int tmpval = abs(t.first - i) + abs(t.second - j);
					tmpminval = tmpminval > tmpval ? tmpval : tmpminval;
				}
				accum += tmpminval;
			}
		}
	}
	return accum;
}
void back(int cnt, int y, int x) {
	if (cnt == total_minus_m) {
		int tmp = calc_dist();
		minval = minval < tmp ? minval : tmp;
		return;
	}
	for (int j = x + 1; j < n; j++) {
		if (city[y][j] == 2) {
			s.erase(s.find((make_pair(y, j))));
			back(cnt + 1, y, j);
			s.insert(make_pair(y, j));
		}
	}
	for (int i = y + 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (city[i][j] == 2) {
				s.erase(s.find((make_pair(i, j))));
				back(cnt + 1, i, j);
				s.insert(make_pair(i, j));
			}
		}
	}
}
int main()
{
	FAST;
	cin >> n >> m;
	total_minus_m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) {
				total_minus_m++;
				s.insert(make_pair(i, j));
			}
		}
	}
	total_minus_m -= m;
	if (total_minus_m == 0) {
		cout << calc_dist();
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (city[i][j] == 2) {
				s.erase(s.find((make_pair(i, j))));
				back(1, i, j);
				s.insert(make_pair(i, j));
			}
		}
	}
	cout << minval;
	return 0;
}