#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
struct edge
{
    int src, dest, weight;
    bool operator<(const edge &next) const
    {
        return weight > next.weight;
    }
};
int v, e, n_included_edge = 0;
long long accum = 0;
vector<vector<edge>> graph;
bool found[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> v >> e;
    graph.assign(v + 1, vector<edge>());
    memset(found, false, sizeof(found));
    priority_queue<edge> pq;
    int src, dest, weight;
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({src, dest, weight});
        graph[dest].push_back({dest, src, weight});
    }
    for (const auto &iter : graph[1])
    {
        pq.push({1, iter.dest, iter.weight});
    }
    found[1] = true;
    while (n_included_edge < v - 1)
    {
        edge now = pq.top();
        pq.pop();
        if (found[now.dest])
            continue;
        found[now.dest] = true;
        n_included_edge++;
        accum += now.weight;
        for (const auto &iter : graph[now.dest])
        {
            pq.push({iter.src, iter.dest, iter.weight});
        }
    }
    cout << accum << '\n';
    return 0;
}