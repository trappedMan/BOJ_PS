#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v, ss;
bool p[500001];
int pp[100000];
int bin_search(int start, int end, int val)
{
    if (start > end)
        return start;
    else if (start == end)
    {
        //이 부분에서 인덱스를 소홀히 다뤘음. LIS는 인덱스 리턴 전에 찾는 값이 그 인덱스에서의 값보다 크다면 그 다음 인덱스를 리턴해야만 한다.(그렇지 않으면 오류가 발생한다)
        if (v[start].second < val)
            return start + 1;
        else
            return start;
    }
    int mid = (start + end) / 2;
    if (v[mid].second < val)
        return bin_search(mid + 1, end, val);
    else
        return bin_search(start, mid - 1, val);
}
int main()
{
    FAST;
    int n;
    cin >> n;
    ss.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i].first >> ss[i].second;
        p[ss[i].first] = true;
    }
    sort(ss.begin(), ss.end());
    v.push_back(ss[0]);
    pp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int pos;
        if (v[v.size() - 1].second < ss[i].second)
        {
            v.push_back(ss[i]);
            pp[i] = v.size() - 1;
        }
        else
        {
            pos = bin_search(0, v.size() - 1, ss[i].second);
            v[pos] = ss[i];
            pp[i] = pos;
        }
    }
    int cnt = v.size() - 1;
    for (int i = n - 1; i >= 0 && cnt >= 0; i--)
    {
        if (pp[i] == cnt)
        {
            p[ss[i].first] = false;
            cnt--;
        }
    }
    cout << n - v.size() << '\n';
    for (int i = 0; i <= 500000; i++)
        if (p[i])
            cout << i << '\n';
    return 0;
}