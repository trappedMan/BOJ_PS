//어차피 모든 점을 돌기 때문에 시작점은 의미없음
#include <iostream>
#include <memory.h>
using namespace std;
int adjmat[16][16];
int dp[65600][16];
int n, allvisit;
const int INF = 1000000000;
int pow()
{
    int mul = 1, i = n;
    while (i--)
        mul *= 2;
    return mul;
}
int func(int visit, int now)
{
    int minval = INF, tmp;
    if (dp[visit][now] != -1)
        return dp[visit][now];
    if (visit == allvisit)
    {
        if (!adjmat[now][0])
            return INF;
        else
            return adjmat[now][0];
    }
    for (int i = 1; i < n; i++)
    {
        if (!adjmat[now][i] || (visit >> i) & 1 == 1)
            continue;
        tmp = func(visit | 1 << i, i) + adjmat[now][i];
        minval = min(tmp, minval);
    }
    dp[visit][now] = minval;
    return minval;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    allvisit = pow() - 1;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjmat[i][j];
    cout << func(1, 0) << '\n';
    return 0;
}