#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
vector<int> v, ss, pp, p;
int bin_search(int start, int end, int val)
{
    if (start > end)
        return start;
    else if (start == end)
    {
        if (v[start] < val)
            return start + 1;
        else
            return start;
    }
    int mid = (start + end) / 2;
    if (v[mid] < val)
        return bin_search(mid + 1, end, val);
    else
        return bin_search(start, mid - 1, val);
}
int main()
{
    FAST;
    int n;
    cin >> n;
    ss.resize(n), pp.resize(n);
    for (int i = 0; i < n; i++)
        cin >> ss[i];
    v.push_back(ss[0]);
    pp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int pos;
        if (v[v.size() - 1] < ss[i])
        {
            v.push_back(ss[i]);
            pp[i] = v.size() - 1;
        }
        else
        {
            pos = bin_search(0, v.size() - 1, ss[i]);
            v[pos] = ss[i];
            pp[i] = pos;
        }
    }
    int cnt = v.size() - 1;
    for (int i = n - 1; i >= 0 && cnt >= 0; i--)
    {
        if (pp[i] == cnt)
        {
            p.push_back(ss[i]);
            cnt--;
        }
    }
    cout << v.size() << '\n';
    for (auto iter = p.rbegin(); iter != p.rend(); iter++)
        cout << *iter << " ";
    return 0;
}