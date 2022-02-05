#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int m, tmp, b = 0;
    string c;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> c;
        if (c != "all" && c != "empty")
        {
            cin >> tmp;
            if (c == "add")
                b = b | 1 << tmp;
            else if (c == "remove")
                b = b & ~(1 << tmp);
            else if (c == "check")
            {
                if ((b >> tmp) & 1)
                    cout << "1\n";
                else
                    cout << "0\n";
            }
            else if (c == "toggle")
            {
                if ((b >> tmp) & 1)
                    b = b & ~(1 << tmp);
                else
                    b = b | 1 << tmp;
            }
        }
        if (c == "all")
            b = 2097151;
        else if (c == "empty")
            b = 0;
    }
    return 0;
}