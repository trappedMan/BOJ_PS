#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int main()
{
	FAST;
	int n, m, s, d;
	cin >> n >> m;
	vector<int> a(n+1);
	vector<int> sum(n+1);
	a[0] = 0, sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> d;
		cout << sum[d] - sum[s - 1] << '\n';
	}
	return 0;
}