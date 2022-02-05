#include <iostream>
#include <memory.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
//unsigned long long cnt = 0;
ll cnt = 0;
ll dp[1024][10][101];
ll func(unsigned int visit, int prev, int depth)
{
    visit = visit | 1 << prev;
    if (dp[visit][prev][depth] != -1)
    {
        return dp[visit][prev][depth];
    }
    if (depth == 0)
    {
        if (visit == 1023)
            return 1;
        else
            return 0;
    }
    ll val = 0;
    if (prev != 0)
        val += func(visit, prev - 1, depth - 1);
    if (prev != 9)
        val += func(visit, prev + 1, depth - 1);
    val %= INF;
    dp[visit][prev][depth] = val;
    return val;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    unsigned int visit = 0;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 9; i++)
    {
        cnt += func(visit, i, n - 1);
    }
    cnt %= INF;
    cout << cnt;
    return 0;
}