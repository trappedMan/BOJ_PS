#include <iostream>
#include <stack>
using namespace std;
typedef struct _node
{
    int val;
    struct _node *lchild;
    struct _node *rchild;
} node;
node *root;
stack<node *> st;
node *get_node(int val)
{
    node *newnode = new node;
    newnode->lchild = newnode->rchild = NULL;
    newnode->val = val;
    return newnode;
}
void get_preorder(node *now)
{
    int temp;
    while (cin >> temp)
    {
        node *newnode = get_node(temp);
        if (now->val > temp)
        {
            st.push(now);
            now->lchild = newnode;
            now = newnode;
        }
        else
        {
            while (!st.empty() && st.top()->val < temp)
            {
                now = st.top();
                st.pop();
            }
            now->rchild = newnode;
            now = newnode;
        }
    }
}
void postorder(node *root)
{
    if (root->lchild)
        postorder(root->lchild);
    if (root->rchild)
        postorder(root->rchild);
    cout << root->val << '\n';
}
void freetree(node *root)
{
    if (root->lchild)
        freetree(root->lchild);
    if (root->rchild)
        freetree(root->rchild);
    delete root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int temp;
    cin >> temp;
    root = get_node(temp);
    get_preorder(root);
    postorder(root);
    freetree(root);
    return 0;
}