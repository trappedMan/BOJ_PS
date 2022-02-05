#include <iostream>
using namespace std;
int adjmat[10][10];
int n, allvisit, ans = 1000000000;
int pow(int n)
{
    int i = n, mul = 1;
    while (i--)
        mul *= 2;
    return mul;
}
void func(int visit, int now, int sum)
{
    if (visit == allvisit)
    {
        if (adjmat[now][0])
            ans = min(ans, sum + adjmat[now][0]);
        return;
    }
    for (int i = 1; i < n; i++)
        if (((visit >> i) & 1) != 1 && adjmat[now][i])
            func(visit | 1 << i, i, sum + adjmat[now][i]);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    allvisit = pow(n) - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjmat[i][j];
    func(1, 0, 0);
    cout << ans;
    return 0;
}