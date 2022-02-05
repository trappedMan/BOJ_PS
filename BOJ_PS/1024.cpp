#include <cstdio>
int main()
{
    int n, l, i, x;
    scanf("%d %d", &n, &l);
    for (i = l; i <= 100; i++)
    {
        if (i % 2 && n % i == 0)
            break;
        if (i % 2 == 0 && n % i == i / 2)
            break;
    }
    if (i > 101)
    {
        printf("-1\n");
        return 0;
    }
    x = n / i;
    if (i % 2)
    {
        if (x - i / 2 < 0 || (x + i / 2) - (x - i / 2) + 1 > 100)
        {
            printf("-1\n");
            return 0;
        }
        for (int j = x - i / 2; j <= x + i / 2; j++)

            printf("%d ", j);
    }
    else
    {
        if (x - i / 2 + 1 < 0 || (x + i / 2) - (x - i / 2 + 1) + 1 > 100)
        {
            printf("-1\n");
            return 0;
        }
        for (int j = x - i / 2 + 1; j <= x + i / 2; j++)
            printf("%d ", j);
    }
    return 0;
}