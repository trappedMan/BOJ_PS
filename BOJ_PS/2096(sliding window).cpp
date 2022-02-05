#include <cstdio>
#define MAX(a, b) (a > b ? a : b) //이 매크로 식에 ()가 빠지면 오류가 난다
#define MIN(a, b) (a > b ? b : a)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornn(i, l) for (int i = 1; i <= int(l); i++)
int n;
int main()
{
    scanf("%d", &n);
    int maxcost[3] = {0};
    int mincost[3] = {0};
    int cur[3] = {0};
    int a, b, c;
    int temp0, temp1, temp2;
    scanf("%d%d%d", &a, &b, &c);
    maxcost[0] = mincost[0] = a;
    maxcost[1] = mincost[1] = b;
    maxcost[2] = mincost[2] = c;
    forn(i, n - 1)
    {
        scanf("%d%d%d", &a, &b, &c);
        cur[0] = a, cur[1] = b, cur[2] = c;
        temp0 = cur[0] + MAX(maxcost[0], maxcost[1]);
        temp1 = cur[1] + MAX(maxcost[2], MAX(maxcost[0], maxcost[1]));
        temp2 = cur[2] + MAX(maxcost[1], maxcost[2]);
        maxcost[0] = temp0, maxcost[1] = temp1, maxcost[2] = temp2;
        temp0 = cur[0] + MIN(mincost[0], mincost[1]);
        temp1 = cur[1] + MIN(mincost[2], MIN(mincost[0], mincost[1]));
        temp2 = cur[2] + MIN(mincost[1], mincost[2]);
        mincost[0] = temp0, mincost[1] = temp1, mincost[2] = temp2;
    }
    printf("%d %d", MAX(maxcost[2], MAX(maxcost[0], maxcost[1])),
           MIN(mincost[2], MIN(mincost[0], mincost[1])));
    return 0;
}