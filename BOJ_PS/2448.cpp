#include <iostream>
using namespace std;
char tree[3073][6146];
void print_tree(int posx, int posy, int n)
{
    if (n == 3)
    {
        tree[posy][posx] = '*';
        tree[posy + 1][posx - 1] = '*';
        tree[posy + 1][posx + 1] = '*';
        tree[posy + 2][posx - 2] = '*';
        tree[posy + 2][posx - 1] = '*';
        tree[posy + 2][posx] = '*';
        tree[posy + 2][posx + 1] = '*';
        tree[posy + 2][posx + 2] = '*';
    }
    else
    {
        print_tree(posx, posy, n / 2);
        print_tree(posx - n / 2, posy + n / 2, n / 2);
        print_tree(posx + n / 2, posy + n / 2, n / 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, center;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 2 * n - 1; j++)
        {
            tree[i][j] = ' ';
        }
    }
    center = n;
    print_tree(center, 1, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            cout << tree[i][j];
        }
        cout << '\n';
    }
    return 0;
}