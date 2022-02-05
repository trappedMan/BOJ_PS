#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> a, b, c, d;
ll t;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> t >> n;
    ll sum, ans = 0;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            c.push_back(sum);
        }
    }
    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = i; j < m; j++)
        {
            sum += b[j];
            d.push_back(sum);
        }
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    int i = 0, j = d.size() - 1;
    while (i < c.size() && j >= 0)
    {
        ll x = 0, y = 0;
        ll sum = c[i] + d[j];
        if (sum > t)
            j--;
        else if (sum < t)
            i++;
        else
        {
            ll x = 1, y = 1;
            while (++i < c.size())
            {
                if (c[i] != c[i - 1])
                    break;
                else
                    x++;
            }
            while (--j >= 0)
            {
                if (d[j] != d[j + 1])
                    break;
                else
                    y++;
            }
            ans += x * y;
        }
    }
    cout << ans;
    return 0;
}