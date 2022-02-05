#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, s, tmp;
vector<int> seq, a, b;
void makeset(vector<int> &arr, int sum, int start, int end)
{
    if (start == end)
    {
        arr.push_back(sum);
        return;
    }
    makeset(arr, sum, start + 1, end);
    makeset(arr, sum + seq[start], start + 1, end);
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
    sort(seq.begin(), seq.end());
    makeset(a, 0, 0, n / 2);
    makeset(b, 0, n / 2, n);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    int left = 0, right = b.size() - 1, sum;
    while (left < a.size() && right >= 0)
    {
        sum = a[left] + b[right];
        if (sum > s)
            right--;
        else if (sum < s)
            left++;
        else
        {
            int x = a[left], y = b[right];
            long long xcount = 0, ycount = 0;
            while (a[left] == x)
            {
                left++;
                xcount++;
                if (left >= a.size())
                    break;
            }
            while (b[right] == y)
            {
                right--;
                ycount++;
                if (right < 0)
                    break;
            }
            ans += xcount * ycount;
        }
    }
    if (s == 0)
        ans--;
    cout << ans;
    return 0;
}