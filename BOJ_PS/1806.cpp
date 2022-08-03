#include <bits/stdc++.h>
using namespace std;
int n, s, tmp, l = 1, r = 1, mins = 100001;
vector<int> a;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> s;
	a.resize(n + 1);
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		a[i] = a[i - 1] + tmp;
	}
	while (1) {
		if (r>n)
			break;
		if (l > r)
			r = l;
		else if (a[r] - a[l - 1] < s)
			r++;
		else {
			mins = min(mins, r - l + 1);
			l++;
		}
	}
	if (mins == 100001)
		cout << 0;
	else
		cout << mins;
	return 0;
}