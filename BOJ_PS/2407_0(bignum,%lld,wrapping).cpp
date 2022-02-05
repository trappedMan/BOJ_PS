//사람 관점에서는 n>=m 이기 때문에 위의 결과가 정수라는 것을 알 수 있지만, 기계는 그것을 알 수 없기 때문에 큰 수 n과 큰 수 m의 나눗셈을 수행하게 됨.
//이 때, 임의 큰 수의 나눗셈에서는 부동소수점으로 인해 반드시 오차가 존재할 수 밖에 없다
//자료형 생성(type wrapping for operator overloading)
//%lld->signed long long, %llu->unsigend long long
//%15lld면 빈칸 15칸을 만들고 거기에 longlong을 적당히 오른쪽부터 채워넣지만
//%015lld면 15칸을 0으로 채우고 우측부터 적당히 longlong을 채워넣는다.
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef struct _ll
{
    long long BIGNUM = 1e15;
    long long carry;
    long long remainder;
    struct _ll operator+(struct _ll a)
    {
        carry += a.carry;
        remainder += a.remainder;
        if (remainder > BIGNUM)
        {
            carry += remainder / BIGNUM;
            remainder %= BIGNUM;
        }
        return *this;
    }
} ll;
int main()
{
    int n, m;
    cin >> n >> m;
    ll table[101][101];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < m; j++)
            table[i][j].carry = table[i][j].remainder = 0;
    for (int i = 1; i <= n; i++)
    {
        table[i][0].remainder = table[i][i].remainder = 1;
        for (int j = 1; j < i; j++)
        {
            table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        }
    }
    if (table[n][m].carry == 0)
    {
        cout << table[n][m].remainder;
    }
    else
    {
        cout << table[n][m].carry;
        printf("%015lld", table[n][m].remainder);
    }
    return 0;
}