#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	FAST;
	int a, b, v;
	cin >> a >> b >> v;
	if (a >= v)
		cout << 1;
	else {
		if ((v - a) % (a - b) == 0)
			cout << (v - a) / (a - b) + 1;
		else
			cout << (v - a) / (a - b) + 2;
	}
	return 0;
}