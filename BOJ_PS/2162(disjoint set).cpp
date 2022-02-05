#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
struct line
{
    int x1, y1, x2, y2;
    line(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};
vector<line> lines;
int parent[3000];
int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int a, b;
    a = x1 * y2 + x2 * y3 + x3 * y1;
    b = y1 * x2 + y2 * x3 + y3 * x1;
    if (a - b < 0)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}
int dd(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
bool intersect(int i, int j)
{
    int x1, x2, x3, x4, y1, y2, y3, y4, a, b, c, d;
    x1 = lines[i].x1, y1 = lines[i].y1;
    x2 = lines[i].x2, y2 = lines[i].y2;
    x3 = lines[j].x1, y3 = lines[j].y1;
    x4 = lines[j].x2, y4 = lines[j].y2;
    a = CCW(x1, y1, x2, y2, x3, y3);
    b = CCW(x1, y1, x2, y2, x4, y4);
    c = CCW(x3, y3, x4, y4, x1, y1);
    d = CCW(x3, y3, x4, y4, x2, y2);
    if (a * b < 0 && c * d < 0)
        return 1;
    else if (!a && !b && !c && !d)
    {
        if (dd(x1, y1, x2, y2) >= dd(x1, y1, x3, y3) && dd(x1, y1, x2, y2) >= dd(x2, y2, x3, y3) || dd(x1, y1, x2, y2) >= dd(x1, y1, x4, y4) && dd(x1, y1, x2, y2) >= dd(x2, y2, x4, y4) || dd(x3, y3, x4, y4) >= dd(x3, y3, x1, y1) && dd(x3, y3, x4, y4) >= dd(x4, y4, x1, y1) || dd(x3, y3, x4, y4) >= dd(x3, y3, x2, y2) && dd(x3, y3, x4, y4) >= dd(x4, y4, x2, y2))
            return 1;
        else
            return 0;
    }
    else if (a * b == 0 && c * d <= 0)
        return 1;
    else if (c * d == 0 && a * b <= 0)
        return 1;
    else
        return 0;
}
int set_find(int i)
{
    while (parent[i] >= 0)
        i = parent[i];
    return i;
}
void set_union(int i, int j)
{
    i = set_find(i);
    j = set_find(j);
    if (i == j)
        return;
    if (parent[i] > parent[j])
    {
        parent[j] += parent[i];
        parent[i] = j;
    }
    else
    {
        parent[i] += parent[j];
        parent[j] = i;
    }
}
int main()
{
    FAST;
    int n, x1, y1, x2, y2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back(line(x1, y1, x2, y2));
        parent[i] = -1;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (intersect(i, j))
                set_union(i, j);
    int minval = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] < 0)
        {
            cnt++;
            minval = min(minval, parent[i]);
        }
    }
    cout << cnt << '\n';
    cout << -minval << '\n';
    return 0;
}