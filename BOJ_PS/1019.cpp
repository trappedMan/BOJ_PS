#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[10];
void calc(ll n, ll i) {
	while (n > 0) {
		num[n % 10] += i;
		n /= 10;
	}
}
int main()
{
	FAST;
	ll n,a,b,i;
	cin >> n;
	a = 1, b = n; i = 1;
	while (1) {
		while (a % 10 != 0 && a <= b) {
			calc(a, i);
			a++;
		}
		if (a > b)
			break;
		while (b % 10 != 9 && b>=a) {
			calc(b, i);
			b--;
		}
		for (int k = 0; k < 10; k++)
			num[k] += (b/10 - a/10 + 1) * i;
		i *= 10;
		a /= 10; b /= 10;
	}
	for (auto a : num)
		cout << a << " ";
	return 0;
}