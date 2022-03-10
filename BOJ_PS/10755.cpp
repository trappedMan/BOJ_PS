#include <iostream>
#include <vector>
using namespace std;
int g,p,ans = 0;
vector<int> gg, parent, small;
bool flag = true;
int set_find(int n) {
	while (parent[n] >= 0)
		n = parent[n];
	return n;
}
void set_union(int i) {
	if (small[i] < 0) {
		flag = false;
		return;
	}
	i = set_find(i);
	int j = set_find(small[i]);
	if (i == j) {
		flag = false;
		return;
	}
	small[i] = small[j];
	if (parent[i] >= parent[j]) {
		parent[j] += parent[i];
		parent[i] = j;
	}
	else {
		parent[i] += parent[j];
		parent[j] = i;
	}
	ans++;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> g >> p;
	gg.resize(p), parent.resize(g + 1), small.resize(g + 1);
	for (int i = 0; i <= g; i++) {
		parent[i] = -1;
		small[i] = i - 1;
	}
	for (int i = 0; i < p; i++) 
		cin >> gg[i];
	for (int i = 0; i < p && flag; i++) 
		set_union(gg[i]);
	cout << ans;
}