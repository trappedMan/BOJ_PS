#define MIN(a, b) (a > b ? b : a)
#include <cstdio>
int n;
int main()
{
    scanf("%d", &n);
    int cur[3] = {0};
    int mincost[3];
    int min0, min1, min2;
    scanf("%d%d%d", &mincost[0], &mincost[1], &mincost[2]);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d%d", &cur[0], &cur[1], &cur[2]);
        min0 = cur[0] + MIN(mincost[1], mincost[2]);
        min1 = cur[1] + MIN(mincost[0], mincost[2]);
        min2 = cur[2] + MIN(mincost[0], mincost[1]);
        mincost[0] = min0, mincost[1] = min1, mincost[2] = min2;
    }
    printf("%d\n", MIN(MIN(mincost[0], mincost[1]), mincost[2]));
    return 0;
}