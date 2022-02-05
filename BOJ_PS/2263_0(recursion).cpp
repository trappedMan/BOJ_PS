//recursion에서 넘기는 인자를 index로 할때 주의깊게 봐야한다.
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> inorder;
vector<int> postorder;
vector<int> index;
void print_preorder(int instart, int inlast, int poststart, int postlast)
{
    if (instart > inlast || poststart > postlast)
        return;
    int root = postorder[postlast];
    cout << root << " ";
    print_preorder(instart, index[root] - 1, poststart, poststart + index[root] - instart - 1);
    print_preorder(index[root] + 1, inlast, index[root] - instart + poststart, postlast - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    inorder.assign(n, 0), postorder.assign(n, 0), index.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        index[inorder[i]] = i;
    }
    print_preorder(0, n - 1, 0, n - 1);
    return 0;
}