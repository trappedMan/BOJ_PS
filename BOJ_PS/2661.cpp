#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <iostream>
#include <string>
using namespace std;
string str;
int n;
bool done;
bool test(int s) {
	bool flag = false;
	int n = s;
	int i = n - 1;
	int len = 1;
	while (0 <= i) {
		if (!str.substr(i, len).compare(str.substr(n,len))) {
			flag = true;
			break;
		}
		n--;
		i -= 2;
		len++;
	}
	if (flag)
		return false;
	else
		return true;
}

void back(int depth) {
	if (n == depth) {
		if (test(depth-1)) {
			done = true;
			cout << str.substr(0, n);
		}
		return;
	}
	str = str + "1";
	for (int i = 1; i <= 3 && !done; i++) {
		str[depth] = i+'0';
		if (test(depth)) {
			back(depth + 1);
			if (done)
				return;
		}
	}
}
int main()
{
	FAST;
	cin >> n;
	str = str + "1";
	back(1);
	return 0;
}