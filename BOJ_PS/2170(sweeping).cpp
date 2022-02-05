#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    vector<pair<int, int>> lines;
    scanf("%d", &n);
    int a, b;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end());
    pair<int, int> now = {lines[0].first, lines[0].second};
    len += now.second - now.first;
    for (int i = 0; i < n - 1; i++)
    {
        if (now.second >= lines[i + 1].second)
            continue;
        if (lines[i + 1].first <= lines[i].second)
        {
            len += (lines[i + 1].second - lines[i + 1].first) - (now.second - lines[i + 1].first);
            now.second = lines[i + 1].second;
        }
        else
        {
            len += lines[i + 1].second - lines[i + 1].first;
            now.second = lines[i + 1].second;
        }
    }
    printf("%d\n", len);
    return 0;
}