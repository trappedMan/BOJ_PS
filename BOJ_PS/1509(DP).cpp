#define MIN(x, y) (x > y ? y : x)
#include <iostream>
#include <string>
using namespace std;
bool dp1[2500][2500];
int dp2[2500];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string str;
    cin >> str;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        dp1[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp1[i][i + 1] = true;
        }
        else
            dp1[i][i + 1] = false;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (!dp1[j + 1][j + i - 1])
                dp1[j][j + i] = false;
            else
            {
                if (str[j] == str[j + i])
                    dp1[j][j + i] = true;
                else
                    dp1[j][j + i] = false;
            }
        }
    }
    dp2[0] = 1;
    int i, j;
    for (i = 1; i < n; i++)
    {
        dp2[i] = dp2[i - 1] + 1;
        for (j = 0; j <= i; j++)
        {
            if (dp1[j][i] == 1)
            {
                if (j == 0)
                    dp2[i] = 1;
                else
                    dp2[i] = MIN(dp2[j - 1] + 1, dp2[i]);
            }
        }
    }
    cout << str.size() << '\n';
    cout << dp2[n - 1];
    return 0;
}