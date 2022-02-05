#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int maze[1000][1000];
int cost[1000][1000];
int n_destroy[1000][1000];
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int x, int y)
{
    return 0 <= x && x < m && 0 <= y && y < n;
}
void func()
{
    int x, y, b, nowx, nowy, sum;
    queue<tuple<int, int, int, int>> q;
    n_destroy[0][0] = 0;
    q.push({0, 0, 1, 0}); //y,x,cost(sum),num of destroy
    cost[n - 1][m - 1] = -1;
    while (!q.empty())
    {
        auto a = q.front();
        q.pop();
        y = get<0>(a);
        x = get<1>(a);
        sum = get<2>(a);
        b = get<3>(a);
        if (y == n - 1 && x == m - 1)
        {
            cost[n - 1][m - 1] = sum;
            return;
        }
        for (const auto &d : dir)
        {
            nowx = x + d.first, nowy = y + d.second;
            if (!valid(nowx, nowy))
                continue;
            if (n_destroy[nowy][nowx] <= b)
                continue;
            if (maze[nowy][nowx] == 0)
            {
                n_destroy[nowy][nowx] = b;
                q.push({nowy, nowx, sum + 1, b});
            }
            else if (maze[nowy][nowx] == 1 && b < k)
            {
                if (sum % 2)
                {
                    n_destroy[nowy][nowx] = b + 1;
                    q.push({nowy, nowx, sum + 1, b + 1});
                }
                else
                {
                    q.push({y, x, sum + 1, b});
                }
            }
        }
    }
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
        {
            maze[i][j] = s[j] - '0';
            n_destroy[i][j] = 20;
        }
    }
    func();
    cout << cost[n - 1][m - 1];
    return 0;
}