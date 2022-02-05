#define MAX(a, b) a > b ? a : b
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tri[501][501];
    int row;
    cin >> row;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }
    for (int i = 2; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                tri[i][j] += tri[i - 1][j];
            else if (j == i)
                tri[i][j] += tri[i - 1][j - 1];
            else
            {
                tri[i][j] += MAX(tri[i - 1][j - 1], tri[i - 1][j]);
            }
        }
    }
    int maxval = 0;
    for (int j = 1; j <= row; j++)
        if (maxval < tri[row][j])
            maxval = tri[row][j];
    cout << maxval;
    return 0;
}