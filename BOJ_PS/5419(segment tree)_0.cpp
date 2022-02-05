#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef pair<int, int> pii;
pii islands[75003];
int segment_tree[300004];
int n;

//segment tree의 부분합 구하기
int calc_sum(int start, int end, int node, int left, int right)
{
    if (right < start || end < left)
        return 0;
    else if (left <= start && end <= right)
        return segment_tree[node];
    int mid = (start + end) / 2;
    return calc_sum(start, mid, node * 2, left, right) + calc_sum(mid + 1, end, node * 2 + 1, left, right);
}
//segment tree 최신화하기,이 프로그램에선 diff가 항상 1
void update(int start, int end, int node, int index, int diff)
{
    if (index < start || end < index)
        return;
    segment_tree[node] += diff;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}
void solve()
{
    cin >> n;
    int x, y;
    memset(islands, 0, sizeof(islands));
    forn(i, n)
    {
        cin >> x >> y;
        islands[i] = make_pair(x, y);
    }
    //y좌표 기준으로 오름차순 정렬, y좌표 단순화
    sort(islands, islands + n, [](pii &a, pii &b)
         { return a.second < b.second; });
    int yidx = 0;
    int prev = islands[0].second;
    islands[0].second = 0;
    for (int i = 1; i < n; i++)
    {
        if (islands[i].second != prev)
        {
            prev = islands[i].second;
            islands[i].second = ++yidx;
        }
        else
        {
            prev = islands[i].second;
            islands[i].second = yidx;
        }
    }

    memset(segment_tree, 0, sizeof(segment_tree));
    //x좌표 기준으로, x좌표가 같으면 y 기준 내림차순 정렬
    sort(islands, islands + n, [](pii &a, pii &b)
         {
             if (a.first == b.first)
                 return a.second > b.second;
             return a.first < b.first;
         });
    ll result = 0;
    for (int i = 0; i < n; i++)
    {
        result += (ll)calc_sum(0, yidx, 1, islands[i].second, yidx);
        update(0, yidx, 1, islands[i].second, 1);
    }
    printf("%lld\n", result);
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