#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
bool grid[8][8];
bool tmp[8][8];
int ans = -1, tempans = 0, n, m;
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int y, int x)
{
    return 0 <= y && y < 10 && 0 <= x && x < 10;
}
void tgl(int y, int x)
{
    tempans++;
    tmp[y][x] = !tmp[y][x];
    for (const auto &d : dir)
    {
        int yy = y + d.second;
        int xx = x + d.first;
        if (valid(yy, xx))
            tmp[yy][xx] = !tmp[yy][xx];
    }
}
int main()
{
    FAST;
    string str;
    int k;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '*')
                grid[i][j] = true;
            else
                grid[i][j] = false;
        }
    }
    for (int bm = pow(2, n + m - 1) - 1; bm >= 0; bm--)
    {
        memcpy(tmp, grid, sizeof(tmp));
        tempans = 0;
        for (k = 0; k < n; k++)
            if (((bm >> k) & 1))
                tgl(0, k);
        for (k = n; k < n + m - 1; k++)
        {
            if (((bm >> k) & 1))
                tgl(k - n + 1, 0);
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (tmp[i - 1][j - 1])
                    tgl(i, j);

        bool flag = true;
        for (int i = 0; i < n; i++)
            if (tmp[i][m - 1])
                flag = false;
        for (int j = 0; j < m; j++)
            if (tmp[n - 1][j])
                flag = false;
        if (flag)
            ans = max(ans, tempans);
    }
    cout << ans << '\n';
    return 0;
}