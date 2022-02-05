#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
typedef struct _elem
{
    int idx;
    int val;
    int rank;
    int parent;
} elem;
elem disset[51];

int find(int a)
{
    while (disset[a].parent != a)
    {
        a = disset[a].parent;
    }
    return a;
}

void Union(vector<int> list)
{
    for (int i = 0; i < list.size() - 1; i++)
    {
        int leftroot = find(list[i]);
        int rightroot = find(list[i + 1]);
        if (disset[leftroot].rank < disset[rightroot].rank)
        {
            if (disset[rightroot].val == 1)
                disset[leftroot].val = disset[rightroot].val;
            else
                disset[rightroot].val = disset[leftroot].val;
            disset[leftroot].parent = disset[rightroot].idx;
        }
        else
        {
            if (disset[leftroot].val == 1)
                disset[rightroot].val = disset[leftroot].val;
            else
                disset[leftroot].val = disset[rightroot].val;
            disset[rightroot].parent = disset[leftroot].idx;
            if (disset[leftroot].rank == disset[rightroot].rank)
            {
                disset[leftroot].rank++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    vector<int> partyman[51];
    for (int i = 0; i <= 50; i++)
    {
        disset[i].val = -1;
        disset[i].rank = 0;
        disset[i].parent = i;
        disset[i].idx = i;
    }
    int n_know, temp;
    cin >> N >> M;
    cin >> n_know;
    vector<int> tempvec;
    for (int i = 0; i < n_know; i++)
    {
        cin >> temp;
        disset[temp].val = 1;
        tempvec.push_back(temp);
    }
    if (!tempvec.empty())
        Union(tempvec);
    int can_go_count = 0;
    for (int i = 0; i < M; i++)
    {
        int n_partyman, tmp;
        cin >> n_partyman;
        for (int j = 0; j < n_partyman; j++)
        {
            cin >> tmp;
            partyman[i].push_back(tmp);
        }
        Union(partyman[i]);
    }

    for (int i = 0; i < M; i++)
    {
        bool knowflag = false;
        for (const auto &iter : partyman[i])
        {
            if (disset[find(iter)].val == 1)
            {
                knowflag = true;
                break;
            }
        }
        if (!knowflag)
        {
            can_go_count++;
        }
    }
    cout << can_go_count << '\n';
    return 0;
}