#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int maze[1000][1000];
int cost[1000][1000];
bool visits[1000][1000][11];
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int x, int y)
{
    return 0 <= x && x < m && 0 <= y && y < n;
}
void func()
{
    int x, y, nowx, nowy, can_destroy;
    queue<tuple<int, int, int>> q;
    cost[0][0] = 1;
    visits[0][0][k] = true;
    q.push({0, 0, k});
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        y = get<0>(a);
        x = get<1>(a);
        can_destroy = get<2>(a);
        for (const auto &d : dir)
        {
            nowx = x + d.first, nowy = y + d.second;
            if (valid(nowx, nowy))
            {
                if (!visits[nowy][nowx][can_destroy] && maze[nowy][nowx] == 0)
                {
                    visits[nowy][nowx][can_destroy] = true;
                    cost[nowy][nowx] = cost[y][x] + 1;
                    q.push({nowy, nowx, can_destroy});
                }
                else if (!visits[nowy][nowx][can_destroy - 1] && maze[nowy][nowx] == 1 && can_destroy > 0)
                {
                    visits[nowy][nowx][can_destroy - 1] = true;
                    cost[nowy][nowx] = cost[y][x] + 1;
                    q.push({nowy, nowx, can_destroy - 1});
                }
            }
        }
        if (cost[n - 1][m - 1])
            return;
    }
    cost[n - 1][m - 1] = -1;
}
int main()
{
    FAST;
    string s;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            maze[i][j] = s[j] - '0';
    }
    func();
    cout << cost[n - 1][m - 1];
    return 0;
}