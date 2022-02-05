//vector의 reverse 함수 기억

//next_permutation은 현재 vector(iterator을 인자로 받으므로 string도 가능)의 상태에서
//그 다음 수를 나타내는 역할을 한다. 이번처럼 d진법의 수 카운팅에서 유용할 듯

//또 d진수를 10진수로 만들 때 높은 자리수부터 계산하면 굳이 n승을 일일이 계산해서
//더할 필요 없이 해당 자리의 값을 더하고 거기에 d를 곱하고를 반복하면 된다

//vector 식별자 두개를 바로 부등호로 비교하면 pair을 비교할 때처럼 앞의 원소부터 하나씩 비교해
//같으면 다음 원소를 비교하는 식으로 해서 비교한다. 예를 들어{1,2,2}와 {1,2,3}의 두 벡터를 비교하면 우측 vector가 더 큰 것이다

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
int d_to_dec(int d, vector<int> &perm)
{
    int val = 0;
    for (const auto &k : perm)
    {
        val *= d;
        val += k;
    }
    return val;
}
int calc(int n, int d)
{
    while (n)
    {
        num.push_back(n % d);
        n /= d;
    }
    if (num.size() > d)
        return -1;
    num.resize(d);
    reverse(num.begin(), num.end());
    vector<int> perm;
    perm.push_back(1);
    perm.push_back(0);
    for (int i = 2; i < d; i++)
    {
        perm.push_back(i);
    }
    do
    {
        if (perm > num)
        {
            return d_to_dec(d, perm);
        }
    } while (next_permutation(perm.begin(), perm.end()));
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    cout << calc(n, d) << '\n';
    return 0;
}