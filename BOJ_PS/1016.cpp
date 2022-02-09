#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mn, mx;
ll mo[1001001];
ll calc(ll n)
{
	ll tmp = n;
	for (ll i = 2; i * i <= n; i++)
	{
		tmp += mo[i] * (n / (i * i));
	}
	return tmp;
}
void make_mo()
{
	mo[1] = 1;
	for (int i = 1; i <= 1001000; i++)
	{
		for (int j = 2 * i; j <= 1001000; j += i)
		{
			mo[j] -= mo[i];
		}
	}
}
int main()
{
	FAST;
	cin >> mn >> mx;
	make_mo();
	cout << calc(mx) - calc(mn - 1);
	return 0;
}