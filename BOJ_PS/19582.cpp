#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x[100001], p[100001];
ll st[100001];
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> p[i];
	}
	st[0] = p[0];
	int maxp = p[0];
	for (int i = 1; i < n; i++) {
		maxp = max(maxp, p[i]);
		if (st[i - 1] <= x[i]) {
			st[i] = st[i - 1] + p[i];
		}
		else {
			int temp = st[i - 1] - maxp;
			cnt++;
			if (temp > x[i]) {
				st[i] = st[i - 1];
			}
			else {
				st[i] = temp + p[i];
			}
			if (cnt >= 2)
				break;
		}
	}
	if (cnt<2)
		cout << "Kkeo-eok";
	else
		cout << "Zzz";
	return 0;
}