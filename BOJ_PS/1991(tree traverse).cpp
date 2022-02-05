//tree traverse with tree(vector)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
typedef struct _node
{
    char ch;
    struct _node *lchild;
    struct _node *rchild;
} node;
vector<node> tree;
void preorder(node &root)
{
    cout << root.ch;
    if (root.lchild)
        preorder(*(root.lchild));
    if (root.rchild)
        preorder(*(root.rchild));
}
void inorder(node &root)
{
    if (root.lchild)
        inorder(*(root.lchild));
    cout << root.ch;
    if (root.rchild)
        inorder(*(root.rchild));
}
void postorder(node &root)
{
    if (root.lchild)
        postorder(*(root.lchild));
    if (root.rchild)
        postorder(*(root.rchild));
    cout << root.ch;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    tree.assign(n + 1, {'A', NULL, NULL});
    char temp = 'A';
    for (int i = 1; i <= n; i++)
        tree[i].ch = temp++;

    char parent, lchild, rchild;
    for (int i = 1; i <= n; i++)
    {
        cin >> parent >> lchild >> rchild;
        if (lchild != '.')
            tree[parent - 'A' + 1].lchild = &tree[lchild - 'A' + 1];
        if (rchild != '.')
            tree[parent - 'A' + 1].rchild = &tree[rchild - 'A' + 1];
    }
    preorder(tree[1]);
    cout << '\n';
    inorder(tree[1]);
    cout << '\n';
    postorder(tree[1]);
    return 0;
}