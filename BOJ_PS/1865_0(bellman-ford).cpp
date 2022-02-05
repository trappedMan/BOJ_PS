//bellman ford의 경우 stage 0이 dist에 시작점만 0, 나머지 INF을 주고
//stage 1이 시작점과 연결된 곳들의 dist를 최신화 하는 stage라 하면
//stage n-1까지 진행한 뒤엔 더이상 진행해도 dist 값이 변하지 않아야 한다.
//만약 어떤 점에서 bellman-ford를 했는데 stage n에서 또 변하면 음수 사이클이 존재한단 말.
//(사실 connected component가 1개가 아니라면 이론적으로 INF가 변하지 않으므로 오류가 생기는 알고리즘
//인데, 여기선 연결되지 않아 있어도 INF에 음수 weight들이 계속 더해져 실제 계산으로는 계속 dist가 최신화된다)
//!!상당히 많이 도는 반복문에서 바로 리턴을 때려버리면 희한하게 동작 시간이 꽤 늘어난다.
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
typedef struct _info
{
    int src, dest, weight;
} info;
vector<vector<edge>> graph;
int n, m, w;

int bellmanford(int src, int dest, int *dist)
{
    dist[src] = 0;
    for (const auto &iter : graph[src])
        if (dist[iter.dest] > iter.weight)
            dist[iter.dest] = iter.weight;
    for (int i = 2; i <= n - 1; i++)
    {
        for (int t = 1; t <= n; t++)
        {
            for (const auto &iter : graph[t])
            {
                if (dist[iter.dest] > dist[t] + iter.weight)
                    dist[iter.dest] = dist[t] + iter.weight;
            }
        }
    }
    bool flag = false;
    for (int t = 1; t <= n; t++)
    {
        for (const auto &iter : graph[t])
        {
            if (dist[iter.dest] > dist[t] + iter.weight)
            {
                cout << "YES\n";
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        return 0;
    return 1;
}

void solve()
{
    cin >> n >> m >> w;
    graph.assign(n + 1, vector<edge>());
    int src, dest, weight;
    int dist[501];
    forn(i, m)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});
    }
    forn(i, w)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, -weight});
    }
    fornn(i, 500)
        dist[i] = INF;
    if (bellmanford(1, n, dist) == 0)
        return;
    cout << "NO\n";
}

bool multi = true;
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