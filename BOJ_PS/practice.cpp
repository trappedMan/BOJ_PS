#include <iostream>
using namespace std;

struct node
{
    typedef node *pointer;

    node(int);

    int number;
    pointer left, right;
};

/*
binary search tree 
*/
class bst
{
private:
    static const bool LEFT = false;
    static const bool RIGHT = true;

public:
    bst();
    ~bst();

    void insert_node(int);
    void search() const; // post order

private:
    void delete_node(node::pointer, bool, node::pointer);
    void insert_node(node::pointer, int);
    void post_order(node::pointer) const;

private:
    node::pointer _root;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bst tree;
    int number;
    while (cin >> number)
    {
        tree.insert_node(number);
    }

    tree.search();

    return 0;
}

node::node(int number) : number(number), left(nullptr), right(nullptr) {}

bst::bst() : _root(nullptr)
{
}

bst::~bst()
{
    delete_node(nullptr, false, _root);
}

void bst::delete_node(node::pointer parent, bool which, node::pointer p)
{
    if (p->left != nullptr)
        delete_node(p, LEFT, p->left);
    if (p->right != nullptr)
        delete_node(p, RIGHT, p->right);
    if (p->left == nullptr && p->right == nullptr)
    {
        if (parent != nullptr)
        {
            if (which)
                parent->right = nullptr;
            else
                parent->left = nullptr;
        }
        delete p;
        return;
    }
}

void bst::insert_node(int number)
{
    if (_root == nullptr)
    {
        _root = new node(number);
    }
    else
    {
        insert_node(_root, number);
    }
}

void bst::insert_node(node::pointer p, int number)
{
    if (number < p->number)
    {
        if (p->left == nullptr)
            p->left = new node(number);
        else
            insert_node(p->left, number);
    }
    else if (number > p->number)
    {
        if (p->right == nullptr)
            p->right = new node(number);
        else
            insert_node(p->right, number);
    }
}

void bst::search() const
{
    post_order(_root);
}

void bst::post_order(node::pointer p) const
{
    if (p->left != nullptr)
        post_order(p->left);
    if (p->right != nullptr)
        post_order(p->right);
    cout << p->number << '\n';
}