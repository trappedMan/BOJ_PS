#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//qsort의 comp 함수는 리턴타입이 int로서 const void*로 인자를 받아 1,0,-1을 리턴해준다.
//1을 리턴하면 swap이 필요하다고 이해하자
int qcomp(const void *a, const void *b)
{
	int aa = *(int *)a;
	int bb = *(int *)b;
	if (aa > bb)
		return 1;
	else if (aa == bb)
		return 0;
	else
		return -1;
}

//vector든 그냥 array든 sort 함수의 세번째 인자로서 들어가는 이 비교함수는 리턴타입이 bool로서 false인 경우 swap하도록함(true 방향과 동일하게 정렬)
bool sortcomp(const int &a, const int &b)
{
	if (a > b)
		return false;
	else
		return true;
}
//class나 struct를 따로 정의해서 거기서 연산자를 오버로딩시켜야 하는 경우.
//비교 매커니즘은 sortcomp와 반대로 true면 swap하도록 함(false 방향으로 정렬)
class classcomp
{
public:
	bool operator()(const int &a, const int &b)
	{
		if (a > b)
			return false;
		else
			return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, command;
	int a[10] = {8, 1, 4, 9, 2, 3, 6, 5, 7, 0};
	vector<int> b;
	b.push_back(8);
	b.push_back(1);
	b.push_back(4);
	b.push_back(9);
	b.push_back(2);
	b.push_back(3);
	b.push_back(6);
	b.push_back(5);
	b.push_back(7);
	b.push_back(0);
	priority_queue<int, vector<int>, classcomp> pq;
	pq.push(8);
	pq.push(1);
	pq.push(4);
	pq.push(9);
	pq.push(2);
	pq.push(3);
	pq.push(6);
	pq.push(5);
	pq.push(7);
	pq.push(0);
	qsort(a, 10, sizeof(int), qcomp);
	sort(b.begin(), b.end(), sortcomp);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " " << b[i] << " " << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}