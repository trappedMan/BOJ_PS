#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define MIN(x, y) ((x) = min((x), (y)))
#define MAX(x, y) ((x) = max((x), (y)))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornn(i, l) for (int i = 1; i <= int(l); i++)
#define INF (1e9)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct _edge
{
    int dest, weight;
} edge;
int v;
vector<vector<edge>> graph;
int dfs(int src, bool is_second_proc = false)
{
    stack<int> dfsst;
    vector<bool> visit(v + 1, false);
    vi dist(v + 1, 0);
    dfsst.push(src);
    visit[src] = true;
    int cur;
    while (!dfsst.empty())
    {
        cur = dfsst.top();
        dfsst.pop();
        visit[cur] = true;
        for (const auto &iter : graph[cur])
        {
            if (!visit[iter.dest])
                if (dist[iter.dest] < dist[cur] + iter.weight)
                {
                    dist[iter.dest] = dist[cur] + iter.weight;
                    dfsst.push(iter.dest);
                }
        }
    }
    int max = dist[1], maxpos = 1;
    fornn(i, v)
    {
        if (max < dist[i])
        {
            max = dist[i];
            maxpos = i;
        }
    }
    if (is_second_proc)
        return max;
    else
        return maxpos;
}
void solve()
{
    cin >> v;
    graph.assign(v + 1, vector<edge>());
    int src, dest, weight;
    int far, diam;
    forn(i, v - 1)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});
    }
    far = dfs(1);
    diam = dfs(far, true);
    cout << diam;
}

bool multi = false;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    if (multi)
        cin >> t;
    while (t--)
        solve();
    return 0;
}