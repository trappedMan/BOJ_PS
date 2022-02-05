//LIS의 길이는 배열 마지막 원소의 값이 아니라 배열 중 최댓값이다
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ss;
int dp[100];
int main()
{
    FAST;
    int n, j;
    cin >> n;
    ss.resize(n);
    for (int i = 0; i < n; i++)
        cin >> ss[i].first >> ss[i].second;
    sort(ss.begin(), ss.end());
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (ss[j].second < ss[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, dp[i]);
    cout << n - maxval << '\n';
    return 0;
}