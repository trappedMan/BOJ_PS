//https://degurii.tistory.com/47
//점 a,b,c에 대해 ab기준으로 ac가 반시계인지 시계인지 판단하려면
//x1*y2+x2*y3+x3*y1-(y1*x2+y2*x3+y3*x1)>0이면 반시계
//세 점이 같은 직선 위에 있는 경우는 제외한 체크
#include <iostream>
using namespace std;
typedef long long ll;
ll CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll a, b;
    a = x1 * y2 + x2 * y3 + x3 * y1;
    b = y1 * x2 + y2 * x3 + y3 * x1;
    if (a - b < 0)
        return -1;
    else
        return 1;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll x1, x2, x3, x4, y1, y2, y3, y4, a, b, c, d;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    a = CCW(x1, y1, x2, y2, x3, y3);
    b = CCW(x1, y1, x2, y2, x4, y4);
    c = CCW(x3, y3, x4, y4, x1, y1);
    d = CCW(x3, y3, x4, y4, x2, y2);
    if (a * b > 0 || c * d > 0)
        cout << "0\n";
    else
        cout << "1\n";
    return 0;
}