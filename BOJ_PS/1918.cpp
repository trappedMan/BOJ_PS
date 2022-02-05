//열거형(enum)사용한 infix->postfix changing
//stack을 사용하는데, income과 instack의 left parentheses 우선순위가 다른 것을
//enum형 static int 배열로 처리해준 모습이다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define MIN(x, y) ((x) = min((x), (y)))
#define MAX(x, y) ((x) = max((x), (y)))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornn(i, l) for (int i = 1; i <= int(l); i++)
#define INF (1e9)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef enum
{
    leftpr = 0,
    mi,
    pl,
    divd,
    mult,
    rightpr
} Precedence;
static int income[] = {10, 5, 5, 6, 6, 9};
static int instack[] = {0, 5, 5, 6, 6, 9};
static char symbol[] = {'(', '-', '+', '/', '*', ')'};
Precedence gettoken(const char &a)
{
    switch (a)
    {
    case '+':
        return pl;
        break;
    case '-':
        return mi;
        break;
    case '*':
        return mult;
        break;
    case '/':
        return divd;
        break;
    case '(':
        return leftpr;
        break;
    case ')':
        return rightpr;
        break;
    }
}

void solve()
{
    stack<Precedence> op;
    string str;
    cin >> str;
    char now;
    Precedence oprt;
    forn(i, str.size())
    {
        now = str[i];
        if (now == '+' || now == '-' || now == '*' || now == '/' || now == '(' || now == ')')
        {
            oprt = gettoken(now);
            if (op.empty())
                op.push(oprt);
            else if (oprt != rightpr)
            {
                while (!op.empty() && instack[op.top()] >= income[oprt])
                {
                    cout << symbol[op.top()];
                    op.pop();
                }
                op.push(oprt);
            }
            else
            {
                while (!op.empty() && op.top() != leftpr)
                {
                    cout << symbol[op.top()];
                    op.pop();
                }
                op.pop();
            }
        }
        else
            cout << now;
    }
    while (!op.empty())
    {
        cout << symbol[op.top()];
        op.pop();
    }
}

bool multi = false;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    if (multi)
        cin >> t;
    while (t--)
        solve();
    return 0;
}