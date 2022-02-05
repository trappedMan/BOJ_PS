#include <iostream>
#include <vector>
#include <string>
using namespace std;
int ans = 0;
vector<string> vec;
int checkstr(int set)
{
    bool flag;
    int cnt = 0;
    for (const auto &iter : vec)
    {
        flag = true;
        for (int i = 0; i < iter.size(); i++)
        {
            if (!((set >> (iter[i] - 'a')) & 1))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }
    return cnt;
}
void func(int set, char c, int k)
{
    if (k == 0)
    {
        int ret = checkstr(set);
        if (ans < ret)
            ans = ret;
        return;
    }
    if (c > 'z')
        return;
    if (!(set >> (c - 'a' + 1) & 1))
    {
        char tmp = c + 1;
        func(set | 1 << (c - 'a'), tmp, k - 1);
        func(set, tmp, k);
    }
    else
    {
        char tmp = c + 2;
        func(set | 1 << (c - 'a'), tmp, k - 1);
        func(set, tmp, k);
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k, set = 0;
    string str;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        str = str.substr(4, str.size() - 8);
        vec.push_back(str);
    }
    if (k < 5)
    {
        cout << "0\n";
        return 0;
    }
    else
    {
        set = set | 1;
        set = set | 1 << ('n' - 'a');
        set = set | 1 << ('t' - 'a');
        set = set | 1 << ('i' - 'a');
        set = set | 1 << ('c' - 'a');
        k -= 5;
    }
    char c = 'b';
    func(set, c, k);
    cout << ans;
    return 0;
}