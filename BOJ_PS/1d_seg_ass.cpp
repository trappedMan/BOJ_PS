#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <memory>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

typedef long long ll;
vector<ll> seg_tree;
vector<ll> seq;

void make_seg(int start, int end, int root)
{
    if (start == end)
    {
        seg_tree[root] = seq[start];
        return;
    }
    int mid = (start + end) / 2;
    make_seg(start, mid, root * 2);
    make_seg(mid + 1, end, root * 2 + 1);
    seg_tree[root] = seg_tree[root * 2] + seg_tree[root * 2 + 1];
}
void update(int start, int end, int root, int index, ll dif)
{
    if (index < start || end < index)
        return;
    seg_tree[root] += dif;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, root * 2, index, dif);
    update(mid + 1, end, root * 2 + 1, index, dif);
}
ll sum(int start, int end, int root, int low, int high)
{
    if (high < start || end < low)
        return 0;
    if (low <= start && end <= high)
        return seg_tree[root];
    int mid = (start + end) / 2;
    return sum(start, mid, root * 2, low, high) + sum(mid + 1, end, root * 2 + 1, low, high);
}

int main() {

    int n, m;
    FILE* in = fopen("input_assignment1.txt", "r");
    //FILE* in = fopen("input1.txt", "r");
    fscanf(in, "%d", &n);
	seg_tree.resize(4 * n);
	seq.resize(n);
    int temp;
    for (int i = 0; i < n; i++) {
        fscanf(in, "%lld", &seq[i]);
        printf("%lld ", seq[i]);
    }
    printf("\n");
	make_seg(0, n - 1, 1);

    fscanf(in, "%d", &m);
    for (int i = 0; i < m; i++) {

        fscanf(in, "%d\n", &temp);

        if (temp == 0) {
            int st, ed;
            fscanf(in, "%d %d", &st, &ed);
            printf("sum (%d,%d): %lld\n", st, ed, sum(0,n-1,1,st,ed));

        }
        else {
            ll idx, num;
            fscanf(in, "%lld %lld", &idx, &num);
            ll tmp = num - seq[idx];
            seq[idx] = num;
            printf("change %dth elem with %d\n", idx + 1, num);
			update(0, n - 1, 1, idx, tmp);

        }
    }
	fclose(in);
    return 0;

}