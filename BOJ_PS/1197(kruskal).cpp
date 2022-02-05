#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
struct edge
{
    int src, dest, weight;
    bool operator<(const edge &next)
    {
        return weight < next.weight;
    }
};
int v, e, n_included_edge = 0;
long long accum = 0;
vector<edge> graph;
int parent[10001];
int set_find(int n)
{
    while (parent[n] > 0)
    {
        n = parent[n];
    }
    return n;
}
void set_union(int a, int b)
{
    a = set_find(a);
    b = set_find(b);
    if (parent[a] < parent[b])
    {
        parent[a] += parent[b];
        parent[b] = a;
    }
    else
    {
        parent[b] += parent[a];
        parent[a] = b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> v >> e;
    int src, dest, weight;
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest >> weight;
        graph.push_back({src, dest, weight});
    }
    sort(graph.begin(), graph.end());

    for (const auto &iter : graph)
    {
        if (set_find(iter.src) != set_find(iter.dest))
        {
            accum += iter.weight;
            set_union(iter.src, iter.dest);
            n_included_edge++;
        }
        if (n_included_edge == v - 1)
            break;
    }
    cout << accum << '\n';
    return 0;
}