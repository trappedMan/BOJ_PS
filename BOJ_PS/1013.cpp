#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define FAIL {flag=false;break;}
#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
	string str;
	int i, j;
	bool flag = true;
	cin >> str;
	for (i = 0; i < str.size();) {
		if (str[i] == '1') {
			if (i + 2 >= str.size())
				FAIL;
			if (str[i + 1] != '0' || str[i + 2] != '0') 
				FAIL;
			for (j = i + 3; j < str.size(); j++)
				if (str[j] != '0')
					break;
			if (j == str.size())
				FAIL;
			for (; j < str.size(); j++)
				if (str[j] != '1')
					break;
			if (j == str.size())
				break;
			if (j == str.size()-1) 
				FAIL;
			if (str[j + 1] == '0') {
				if (str[j - 2] == '0') {
					FAIL;
				}
				i = j - 1;
			}
			else
				i = j;

		}
		else {
			if (i + 1 >= str.size())
				FAIL;
			if (str[i + 1] != '1')
				FAIL;
			i += 2;
		}

	}
	cout << (flag ? "YES\n" : "NO\n");
}
int main()
{
	FAST;
	cin >> t;
	while (t--)
		solve();
	return 0;
}