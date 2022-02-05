#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <stack>
using namespace std;
typedef struct _edge
{
    int weight;
    int dest;
} edge;
vector<vector<edge>> graph;
bool isvisited[100001];
int farvertexnum;
int dfs(int src)
{
    int max = 0;
    int count = 0;
    stack<edge> dfsst;
    for (const auto &iter : graph[src])
        dfsst.push(iter);
    isvisited[src] = true;
    while (!dfsst.empty())
    {
        edge now = dfsst.top();
        dfsst.pop();
        if (isvisited[now.dest])
        {
            count -= now.weight;
            continue;
        }
        else
        {
            isvisited[now.dest] = true;
            count += now.weight;
            if (count > max)
            {
                max = count;
                farvertexnum = now.dest;
            }
            dfsst.push(now);
        }

        for (const auto &iter : graph[now.dest])
        {
            if (!isvisited[iter.dest])
            {
                dfsst.push(iter);
            }
        }
    }
    return max;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v;
    cin >> v;
    graph.reserve(v + 1);
    graph.resize(v + 1);
    int dest, weight, count;
    edge now;
    for (int i = 1; i <= v; i++)
    {
        int tmp;
        cin >> tmp;
        while (1)
        {
            cin >> dest;
            if (dest == -1)
                break;
            cin >> weight;
            now.dest = dest;
            now.weight = weight;
            graph[tmp].push_back(now);
        }
    }
    int cost;
    memset(isvisited, false, v + 1);
    dfs(1);
    //cout << farvertexnum << " ";
    memset(isvisited, false, v + 1);
    cost = dfs(farvertexnum);
    cout << cost << '\n';
    return 0;
}