#include <cstdio>
#include <iostream>
int seq[2001];
bool dp[2001][2001];
int main()
{
    int n, k, s, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &seq[i]);
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if (seq[i] == seq[i + 1])
            dp[i][i + 1] = 1;
        else
            dp[i][i + 1] = 0;
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (!dp[j + 1][j + i - 1])
                dp[j][j + i] = 0;
            else
            {
                if (seq[j] == seq[j + i])
                    dp[j][j + i] = 1;
                else
                    dp[j][j + i] = 0;
            }
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s - 1][e - 1]);
    }
    return 0;
}