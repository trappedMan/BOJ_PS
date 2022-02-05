#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
bool grid[10][10];
bool tmp[10][10];
int ans = -1, tempans = 0;
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
    for (int i = 0; i < 10; i++)
    {
        cin >> str;
        for (int j = 0; j < 10; j++)
        {
            if (str[j] == 'O')
                grid[i][j] = true;
            else
                grid[i][j] = false;
        }
    }
    for (int bm = 1023; bm >= 0; bm--)
    {
        memcpy(tmp, grid, sizeof(tmp));
        tempans = 0;
        for (int k = 0; k < 10; k++)
            if (((bm >> k) & 1))
                tgl(0, k);

        for (int i = 1; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (tmp[i - 1][j])
                    tgl(i, j);

        bool flag = true;
        for (int j = 0; j < 10; j++)
            if (tmp[9][j])
                flag = false;
        if (flag)
            ans = max(ans, tempans);
    }
    cout << ans << '\n';
    return 0;
}