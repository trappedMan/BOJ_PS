//거듭제곱의 divide-and-conquer. log n time
//(a*b)mod c=((a mod c) * (b mod c)) mod c
//modulo operator %은 +,-와 우선순위가 같다
//int 최대값의 제곱은 long long 범위 내다
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define MIN(x, y) ((x) = min((x), (y)))
#define MAX(x, y) ((x) = max((x), (y)))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornn(i, l) for (int i = 1; i <= int(l); i++)
#define endl "\n"
#define INF (1e9)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef struct _info
{
    int temp;
} info;

ll power(ll a, ll b, ll c)
{
    int temp = 1;
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    else
    {
        temp *= power(a, b % 2, c);
        ll tmp = power(a, b / 2, c);
        temp = ((tmp * tmp % c) * (temp % c)) % c;
        return temp;
    }
}

ll calc(ll a, ll b, ll c)
{
    ll ans;
    a %= c;
    ans = power(a, b, c);
    return ans;
}

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << calc(a, b, c) << '\n';
}

bool multi = false;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    if (multi)
        cin >> t;
    while (t--)
        solve();
    return 0;
}