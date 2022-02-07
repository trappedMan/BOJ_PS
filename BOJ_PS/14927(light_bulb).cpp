#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
bool grid[18][18];
bool tmp[18][18];
int ans = 1e9, tempans = 0, n;
pair<int, int> dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int y, int x){return 0 <= y && y < n && 0 <= x && x < n;}
void tgl(int y, int x)
{
    tempans++;
    tmp[y][x] = !tmp[y][x];
    for (const auto& d : dir)
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
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    for (int bm = (1 << n) - 1; bm >= 0; bm--)
    {
        memcpy(tmp, grid, sizeof(tmp));
        tempans = 0;
        for (int k = 0; k < n; k++)
            if (((bm >> k) & 1))
                tgl(0, k);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                if (tmp[i - 1][j])
                    tgl(i, j);

        bool flag = true;
        for (int j = 0; j < n; j++)
            if (tmp[n-1][j]) 
                flag = false;
        if (flag)
            ans = min(ans, tempans);
    }
    cout << ((ans == 1e9) ? -1 : ans);
    return 0;
}