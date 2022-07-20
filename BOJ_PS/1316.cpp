#include <iostream>
#include <string>
using namespace std;
int tc;
string str;
int sum = 0;
bool tmp[32];

void solve() {
	cin >> str;
	for (int i = 0; i < 32; i++)
		tmp[i] = false;
	tmp[str[0] - 'a'] = true;
	for (int i = 1; i < str.length();i++) {
		if (tmp[str[i] - 'a'] && str[i - 1] != str[i])
			return;
		tmp[str[i] - 'a'] = true;
	}
	sum++;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> tc;
	while (tc--)
		solve();
	cout << sum;
}