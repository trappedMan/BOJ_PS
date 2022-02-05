#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[4000], B[4000], C[4000], D[4000];
vector<int> AA, BB;
int bin_search(int val, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (BB[mid] == val)
        return mid;
    else if (BB[mid] > val)
        return bin_search(val, start, mid - 1);
    else
        return bin_search(val, mid + 1, end);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AA.push_back(A[i] + B[j]);
            BB.push_back(C[i] + D[j]);
        }
    }
    sort(AA.begin(), AA.end());
    sort(BB.begin(), BB.end());
    long long ans = 0;
    int left = 0, right = n * n - 1, sum;
    //그림으로 생각하면, 두 포인터가 양 끝단에서 시작해 sum의 크기에 따라 그에 따른
    //구문을 수행. 예를 들어 초기 상태에서 sum이 0보다 크다면 left를 아무리 키워도
    //현재 right에 대하여 sum이 더 커지므로 0이 될 수 없다. 이런 식으로 두 배열을
    //한번씩만 훑으면 끝난다.
    while (left < AA.size() && right >= 0)
    {
        sum = AA[left] + BB[right];
        if (sum > 0)
            right--;
        else if (sum < 0)
            left++;
        else
        {
            int x = AA[left], y = BB[right];
            long long xcount = 0, ycount = 0;
            while (AA[left] == x)
            {
                left++;
                xcount++;
                if (left >= AA.size())
                    break;
            }
            while (BB[right] == y)
            {
                right--;
                ycount++;
                if (right < 0)
                    break;
            }
            ans += xcount * ycount;
        }
    }
    cout << ans;
    return 0;
}