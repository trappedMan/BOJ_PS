//스파게티이므로 실력이 늘면 최적화할것
#include <iostream>
using namespace std;
int n, maxval = 0;
int board[10][10];
bool valid(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < n;
}
bool check_pos(int i, int j)
{
    if (!board[i][j])
        return false;
    int ii = i, jj = j;
    while (valid(ii, jj))
    {
        --ii;
        --jj;
        if (board[ii][jj] == -1)
            return false;
    }
    ii = i, jj = j;
    while (valid(ii, jj))
    {
        --ii;
        ++jj;
        if (board[ii][jj] == -1)
            return false;
    }
    return true;
}
void calc_max(int i, int j, int sum)
{
    if (n * i + j >= n * n)
    {
        maxval = max(sum, maxval);
        return;
    }
    if (n % 2)
    {
        calc_max(i + (j + 2) / n, (j + 2) % n, sum);
        if (check_pos(i, j))
        {
            board[i][j] = -1;
            calc_max(i + (j + 2) / n, (j + 2) % n, sum + 1);
            board[i][j] = 1;
        }
    }
    else
    {
        int jj = (j + 2) % n - (j + 2) / n;
        if (jj < 0)
            jj += 2;
        calc_max(i + (j + 2) / n, jj, sum);
        if (check_pos(i, j))
        {
            board[i][j] = -1;
            calc_max(i + (j + 2) / n, jj, sum + 1);
            board[i][j] = 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    calc_max(0, 0, 0);
    ans += maxval;
    maxval = 0;
    calc_max(0, 1, 0);
    ans += maxval;
    cout << ans << '\n';
    return 0;
}