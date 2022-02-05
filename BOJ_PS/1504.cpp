#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;

#define MIN(x, y) ((x) = min((x), (y)))
#define MAX(x, y) ((x) = max((x), (y)))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define endl "\n"
#define INF (1e9)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct _info
{
    int dest, weight;
} info;

int n, e;
vector<vector<info>> orig;
bool found[801];
void dijkstra(int v, ll *dist)
{
    memset(found, false, 801);
    for (const auto &iter : orig[v])
        if (dist[iter.dest] > iter.weight)
            dist[iter.dest] = iter.weight;
    dist[v] = 0;
    found[v] = true;
    int min, minpos;
    forn(i, n - 2)
    {
        min = INF, minpos = -1;
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] < min && !found[j])
            {
                min = dist[j];
                minpos = j;
            }
        }
        if (minpos == -1)
            break;
        found[minpos] = true;
        for (const auto &iter : orig[minpos])
        {
            if (!found[iter.dest])
                if (dist[iter.dest] > dist[minpos] + iter.weight)
                {
                    dist[iter.dest] = dist[minpos] + iter.weight;
                }
        }
    }
}

void solve()
{
    int v1, v2;
    ll dist_v1[801], dist_v2[801];
    forn(i, 801)
        dist_v1[i] = dist_v2[i] = INF;
    cin >> n >> e;
    orig.assign(n + 1, vector<info>());
    int src, dest, weight;
    forn(i, e)
    {
        cin >> src >> dest >> weight;
        orig[src].push_back({dest, weight});
        orig[dest].push_back({src, weight});
    }
    cin >> v1 >> v2;
    ll maxv1, maxv2, minval = INF;
    dijkstra(v1, dist_v1);
    dijkstra(v2, dist_v2);
    if (dist_v1[1] != INF && dist_v2[n] != INF && dist_v1[v2] != INF)
        minval = dist_v1[1] + dist_v2[n] + dist_v1[v2];
    if (dist_v1[n] != INF && dist_v2[1] != INF && dist_v2[v1] != INF)
    {
        if (minval > dist_v1[n] + dist_v2[1] + dist_v2[v1])
            minval = dist_v1[n] + dist_v2[1] + dist_v2[v1];
    }
    if (minval == INF)
        cout << "-1\n";
    else

        cout << minval << '\n';
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