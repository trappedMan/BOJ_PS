#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> graph;
priority_queue<int, vector<int>, greater<int>> pq;
int indegree[32001];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m, s, d;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    graph.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        cin >> s >> d;
        graph[s].push_back(d);
        indegree[d]++;
    }
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
        {
            pq.push(i);
            indegree[i]--; //indegree를 -1로 바꾸어 큐에 두번 푸쉬되지 않도록함
        }
    for (int i = 1; i <= n; i++)
    {
        int now = pq.top();
        pq.pop();
        cout << now << " ";
        for (const auto &iter : graph[now])
        {
            indegree[iter]--;
            if (!indegree[iter])
            {
                pq.push(iter);
                indegree[iter]--; //indegree를 -1로 바꾸어 큐에 두번 푸쉬되지 않도록함
            }
        }
    }
    return 0;
}