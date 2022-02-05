//struct 내의 부등호 연산자 오버로딩, pq 이용한 dijkstra(! 이 코드는 통째로 외우자 그냥)
//dijkstra에서 정점이 선택될 때마다 dist를 확인하는 건 O(V^2+E),
//Priority Queue를 통해서 모든 간선을 검사하는데, 최악의 경우 모든 간선에 대해 PQ에 정점을 push하므로
//O(ElogE)=O(ElogV)가 된다. 물론 complete graph에 가까울수록 이 두 복잡도는 동일해지지만,
//일반적인 경우 E가 V(V+1)/2에 한참 못미치므로 Priority queue를 이용한 방식이 훨씬 빠르다고 할 것이다.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
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
    int node;
    int accum_cost;
    bool operator<(const struct _info &next) const //typedef struct문에서 이 struct 지칭은 struct _info 처럼 strcut를 붙여주는게 안전하다.(보통 그리고 그렇게 해야된다.)
    {
        return this->accum_cost > next.accum_cost;
    }
} info;

int v, e;
int start;
int *dist;
vector<vector<edge>> graph;
void dijkstra()
{
    //생각해보면 priority queue는 타입 하나만 주면 그 자료형의 대소 비교를 알아서 해서
    //저장을 해준다. 따라서 이 타입에 내가 정의한 struct가 들어가려면 부등호 오버로딩은 자연스럽게
    //해줘야 한다는 생각이 든다.
    priority_queue<info> pq;
    pq.push({start, 0}); //operator overloading된 class는 이런 식으로 인자를 넘길 수 없다. struct라 가능한거임
    info now;
    dist[start] = 0;
    while (!pq.empty())
    {
        now = pq.top();
        pq.pop();
        if (dist[now.node] < now.accum_cost)
            continue;
        for (const auto &iter : graph[now.node])
        {
            if (dist[iter.dest] > dist[now.node] + iter.weight)
            {
                dist[iter.dest] = dist[now.node] + iter.weight;
                pq.push({iter.dest, dist[iter.dest]});
            }
        }
    }
}

void solve()
{
    cin >> v >> e;
    cin >> start;
    graph.assign(v + 1, vector<edge>());
    dist = new int[v + 1];
    fornn(i, v)
        dist[i] = INF;
    int src, dest, weight;
    forn(i, e)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
    }
    dijkstra();
    fornn(i, v)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
    delete[] dist;
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