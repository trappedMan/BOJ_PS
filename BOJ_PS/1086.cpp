#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
typedef long long ll;
int n, mod;
ll cnt;
string num[16];
int tenmod[51];
int nummod[16];
ll dp[1 << 15][101];
ll func(int _bit, int k) {
	if (_bit == (1 << n) - 1)
		return (k % mod == 0);
	ll& ret = dp[_bit][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		if (_bit & (1 << i)) continue;
		ll nextk = k * tenmod[num[i].size()] + nummod[i];
		nextk %= mod;
		ret += func(_bit | (1 << i), nextk);
	}
	return ret;
}

ll gcd(ll a, ll b) {
	if (a < b)
		swap(a, b);
	ll rem;
	while (1)
	{
		rem = a % b;
		if (rem == 0)
			break;
		a = b;
		b = rem;
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	ll tmp = (ll)n;
	ll fact = 1;
	while (tmp) {
		fact *= tmp;
		tmp--;
	}
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> mod;
	tenmod[0] = 1 % mod;
	for (int i = 1; i < 51; i++) {
		tenmod[i] = (tenmod[i - 1] * 10) % mod;
	}
	for (int i = 0; i < n; i++) {
		reverse(num[i].begin(), num[i].end());
		nummod[i] = 0;
		for (int j = 0; j < num[i].size(); j++) {
			nummod[i] += (num[i][j] - '0') * tenmod[j] % mod;
		}
		nummod[i] %= mod;
	}
	memset(dp, -1, sizeof(ll) * (1 << 15) * 101);
	cnt = func(0, 0);
	if (cnt == 0) {
		cout << "0/1";
		return 0;
	}
	tmp = gcd(cnt, fact);
	cout << cnt / tmp << '/' << fact / tmp;
	return 0;
}