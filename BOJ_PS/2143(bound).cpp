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
    for (const auto &iter : c)
    {
        ans += upper_bound(d.begin(), d.end(), t - iter) - lower_bound(d.begin(), d.end(), t - iter);
    }
    cout << ans;
    return 0;
}