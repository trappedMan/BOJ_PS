#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, s, tmp, ans;
vector<int> seq;
void dfs(int sum, int start)
{
    if (start == n)
    {
        if (sum == s)
            ans++;
        return;
    }
    dfs(sum, start + 1);
    dfs(sum + seq[start], start + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        seq.push_back(tmp);
    }
    dfs(0, 0);
    if (s == 0)
        ans--;
    cout << ans;
    return 0;
}