#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <iostream>
#include <string>
using namespace std;
bool a[10001];
int main()
{
	FAST;
	int tmp;
	for (int i = 1; i < 10000; i++) {
		tmp = i / 10000 + (i / 1000) % 10 + (i / 100) % 10 + (i / 10) % 10 + i % 10 + i;
		if (tmp > 0 && tmp <= 10000)
			a[tmp] = true;
	}
	for (int i = 1; i <= 10000; i++) {
		if (!a[i])
			cout << i << '\n';
	}
	return 0;
}