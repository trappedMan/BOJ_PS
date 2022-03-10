#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
int parent[1000000];
int n, m, ans = 0;
bool flag = true;
int set_find(int i) {
	while (parent[i] >= 0)
		i = parent[i];
	return i;
}
void set_union(int i, int j) {
	i = set_find(i);
	j = set_find(j);
	if (i == j) {
		flag = false;
		return;
	}
	if (parent[i] > parent[j]) {
		parent[j] += parent[i];
		parent[i] = j;
	}
	else {
		parent[i] += parent[j];
		parent[j] = i;
	}
}
void func(int i, int j) {
	flag = true;
	while (flag) {
		if (a[i][j] == 'D') {
			set_union(i * m + j, (i + 1) * m + j);
			i++;
		}
		else if (a[i][j] == 'U') {
			set_union(i * m + j, (i - 1) * m + j);
			i--;
		}
		else if (a[i][j] == 'L') {
			set_union(i * m + j, i * m + (j - 1));
			j--;
		}
		else if (a[i][j] == 'R') {
			set_union(i * m + j, i * m + (j + 1));
			j++;
		}
	}
}
int main()
{
	FAST;
	string s;
	cin >> n >> m;
	for (int i = 0; i < 1000000; i++)
		parent[i] = -1;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			a[i][j] = s[j];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			func(i, j);
	for (int i = 0; i < n * m; i++) {
		if (parent[i] < 0)
			ans++;
	}
	cout << ans;
	return 0;
}