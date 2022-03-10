#include <iostream>
using namespace std;
typedef long long ll;
ll a, b;
ll d[55];
ll func(ll n) {
	ll ans = 0;
	for (int i = 54; i >= 1; i--) {
		if (n >= (1LL << i)) {
			ans += d[i - 1] + n - (1LL << i) + 1 + func(n - (1LL << i));
			break;
		}
	}
	if (ans == 0 && (n % 2))
		ans = 1;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> a >> b;
	d[0] = 1;
	for (int i = 1; i < 55; i++) {
		d[i] = d[i - 1] * 2 + (1LL << i);
	}
	cout << func(b) - func(a - 1);
}