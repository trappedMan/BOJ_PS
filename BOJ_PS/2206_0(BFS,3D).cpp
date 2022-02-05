//그래프의 최단 거리를 구하는 것은 dfs가 아니라 bfs로 풀어야 정답임이 보장된다.
//dfs로 메모이제이션 하는 것은 searching에서 선후관계가 없어서 정답이 보장되지 않는다.
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
int n, m;
int ans;
vector<vector<int>> maze;
bool visit[1000][1000][2] = {false};
int cost[1000][1000] = {0};
pair<int, int> direc[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
void search_path()
{
    int x, y, can_destroy;
    int nowx, nowy;
    queue<tuple<int, int, int>> q;
    visit[0][0][1] = true;
    cost[0][0] = 1;
    q.push({0, 0, 1});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        y = get<0>(cur);
        x = get<1>(cur);
        can_destroy = get<2>(cur);
        if (y == n - 1 && x == m - 1)
            return;
        for (const auto &dir : direc)
        {
            nowy = y + dir.first;
            nowx = x + dir.second;
            if (valid(nowy, nowx))
            {
                if (!visit[nowy][nowx][can_destroy] && maze[nowy][nowx] == 0)
                {
                    cost[nowy][nowx] = cost[y][x] + 1;
                    visit[nowy][nowx][can_destroy] = true;
                    q.push({nowy, nowx, can_destroy});
                }
                else if (can_destroy && maze[nowy][nowx] == 1)
                {
                    cost[nowy][nowx] = cost[y][x] + 1;
                    visit[nowy][nowx][0] = true;
                    q.push({nowy, nowx, 0});
                }
            }
        }
    }
    cost[n - 1][m - 1] = -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    string str;
    maze.assign(n, vector<int>());
    for (int i = 0; i < n; i++)
        maze[i].assign(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
            maze[i][j] = str[j] - '0';
    }
    search_path();
    cout << cost[n - 1][m - 1];
    return 0;
}