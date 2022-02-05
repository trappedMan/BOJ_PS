#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int maze[1000][1000];
int group[1000][1000];
vector<int> counts(500001);
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int x, int y)
{
    return 0 <= x && x < m && 0 <= y && y < n;
}
void dfs(int i, int j, int g)
{
    stack<pair<int, int>> s;
    s.push({i, j});
    while (!s.empty())
    {
        auto a = s.top();
        s.pop();
        int y = a.first, x = a.second;
        if (group[y][x])
            continue;
        counts[g]++;
        group[y][x] = g;
        for (const auto &d : dir)
        {
            int nowy = y + d.first, nowx = x + d.second;
            if (valid(nowx, nowy) && !group[nowy][nowx])
                s.push({nowy, nowx});
        }
    }
}
void f()
{
    int g = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!group[i][j])
            {
                dfs(i, j, g);
                ++g;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!maze[i][j])
                cout << maze[i][j];
            else
            {
                set<int> k;
                int tmp = 1;
                for (auto &d : dir)
                {
                    int y = i + d.first, x = j + d.second;
                    if (valid(x, y) && maze[y][x] != 1)
                        k.insert(group[y][x]);
                }
                for (auto &iter : k)
                {
                    tmp += counts[iter];
                }
                cout << tmp % 10;
            }
        }
        cout << '\n';
    }
}

int main()
{
    FAST;
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = s[j] - '0';
            group[i][j] = s[j] - '0';
        }
    }
    f();
    return 0;
}