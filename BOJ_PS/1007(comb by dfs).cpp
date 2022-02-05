//dfs같은 것을 재귀로 짤 때 pruning은 매우 중요하다.
//이 문제에서 단순히 각 조합에 대해 visited 배열을 만들고 20개의 원소에 대해 전부 두 개의 재귀 호출을
//진행하면 2^20의 반복에 대해 visited 배열을 검사하는 과정을 거치지만, 아래와 같이 코딩하면
//20C10 조합 구현에서 to나 from 중 한쪽이 다 할당되면 그 가지는 한쪽으로만 진행할 수 있기 때문에
//훨씬 빠르게 수행될 수 있다.
#define INF 100000000.0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct _point
{
    double x, y;
} point;
point pt[20];
int n;
double x, y;
double minlen;
void dfs(double x, double y, int idx, int to, int from)
{
    if (to == 0 & from == 0)
    {
        if (minlen > sqrt(x * x + y * y))
            minlen = sqrt(x * x + y * y);
        return;
    }
    if (to > 0)
    {
        dfs(x + pt[idx].x, y + pt[idx].y, idx + 1, to - 1, from);
    }
    if (from > 0)
    {
        dfs(x - pt[idx].x, y - pt[idx].y, idx + 1, to, from - 1);
    }
}
void solve()
{
    minlen = INF;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pt[i] = {x, y};
    }
    dfs(0, 0, 0, n / 2, n / 2);
    cout << minlen << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    cout << fixed;
    cout.precision(6);
    while (t--)
        solve();
    return 0;
}