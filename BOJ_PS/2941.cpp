#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <iostream>
#include <string>
using namespace std;
int parse(string str) {
	int ret = str.length();
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == '=' || str[i] == '-') {
			ret--;
			if (i >= 2 && str[i - 2] == 'd' && str[i - 1] == 'z')
				ret--;
		}
		else if (str[i] == 'j' && (str[i - 1] == 'l' || str[i - 1] == 'n')) {
			ret--;
		}
	}
	return ret;
}
int main()
{
	FAST;
	string str;
	cin >> str;
	cout << parse(str);
	return 0;
}