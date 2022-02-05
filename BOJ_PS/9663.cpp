//n-queen problem에서 백트래킹을 시도하면 한번 놓았을 때 아래에 놓을수 없는 위치가 생긴다.
//그렇다면 체스판 int 2차원 배열에 대해 현위치에 말을 놓음으로서 아래에 놓을수 없게된 위치에 +1,
//그 방향의 dfs가 끝날 시 다시 -1을 해주는 식으로 관리하게 된다.
//bool 배열을 사용하지 않는 이유는 백트래킹을 위한 재귀 과정에서 계속 같은 위치에 +1이 중첩되어
//계산되는데 bool 변수에 아무리 1을 더해도 true지만, 거기서 -1을 하면 바로 false가 되기에 오류발생
#include <iostream>
using namespace std;
int n, ans = 0;
int t[15][15];
bool valid(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < n;
}
void check(int flag, int r, int c)
{
    int i = r, j = c;
    while (valid(i, j))
    {
        t[i][j] += flag;
        i++;
    }
    i = r, j = c;
    while (valid(i, j))
    {
        t[i][j] += flag;
        i++, j++;
    }
    i = r, j = c;
    while (valid(i, j))
    {
        t[i][j] += flag;
        i++, j--;
    }
}
void f(int r, int c)
{
    if (r == n - 1)
    {
        ++ans;
        return;
    }
    check(1, r, c);
    for (int i = 0; i < n; i++)
    {
        if (!t[r + 1][i])
            f(r + 1, i);
    }
    check(-1, r, c);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        f(0, i);
    cout << ans;
    return 0;
}