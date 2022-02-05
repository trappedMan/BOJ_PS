#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mo[1000001];
ll calc(ll n)
{
    ll tmp = n;
    for (ll i = 2; i * i <= n; i++)
    {
        tmp += mo[i] * (n / (i * i));
    }
    return tmp;
}
ll bin_search(ll val, ll start, ll end)
{
    if (start > end)
        return -1;
    ll mid = (start + end) / 2;
    if (mid - calc(mid) == val)
        return mid;
    else if (mid - calc(mid) > val)
        return bin_search(val, start, mid - 1);
    else
        return bin_search(val, mid + 1, end);
}
void make_mo()
{
    mo[1] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = 2 * i; j <= 1000000; j += i)
        {
            mo[j] -= mo[i];
        }
    }
}
int main()
{
    FAST;
    ll n;
    cin >> n;
    make_mo();
    ll pos = bin_search(n, 1, 1e11);
    while (pos - calc(pos) == n)
        pos--;
    cout << ++pos;
    return 0;
}