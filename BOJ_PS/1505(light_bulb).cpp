#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
bool grid[8][8];
bool tmp[8][8];
const int INF = 1e9;
int ans = INF, tempans = 0, n, m;
pair<int, int> dir[8] = { {1, 0}, {1,1}, {0, 1}, {-1,1}, {-1, 0}, {-1,-1}, {0, -1}, {1,-1} };
bool valid(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
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
    for (int bm = (1<<n+m-1) - 1; bm >= 0; bm--)
    {
        memcpy(tmp, grid, sizeof(tmp));
        tempans = 0;
        for (k = 0; k < n; k++)
            if (((bm >> k) & 1))
                tgl(k, 0);
        for (k = n; k < n + m - 1; k++)
        {
            if (((bm >> k) & 1))
                tgl(0, k - n + 1);
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (!tmp[i - 1][j - 1])
                    tgl(i, j);

        bool flag = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!tmp[i][j])
                    flag = false;
        if (flag)
            ans = min(ans, tempans);
    }
    if (ans == INF)
        cout << "-1";
    else
        cout << ans << '\n';
    return 0;
}