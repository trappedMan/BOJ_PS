#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cnt = -1, ans = -1;
char x[11];
void print() {
	if (cnt < n) {
		cout << "-1";
		return;
	}
	else
		cout << atol (x);
}
void func(int digit,int num,int high) {
	if (cnt >= n)
		return;
	if (high <= num)
		return;
	if (high != 11 || num != 0)
		high = num;
	x[digit] = num + '0';
	for (int i = 0; i < 10; i++) {
		if(digit+1<10)
		func(digit + 1, i, high);
		else {
			++cnt;
			return;
		}
	}
}
int main()
{
	FAST;
	cin >> n;
	x[10] = '\0';
	for (int i = 0; i < 10; i++)
		func(0, i, 11);
	print();
	return 0;
}