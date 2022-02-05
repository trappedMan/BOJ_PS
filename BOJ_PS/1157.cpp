#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int maxchar[26] = { 0, };
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a')
			str[i] -= 'a' - 'A';
		maxchar[str[i] - 'A']++;
	}
	int max = maxchar[0];
	int index=0;
	for (int i = 1; i < 26; i++) {
		if (maxchar[i] > max) {
			max = maxchar[i];
			index = i;
		}
	}
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (maxchar[i] == max)
			count++;
	}
	if (count > 1) {
		cout << '?' << '\n';
		return 0;
	}
	cout << (char)('A' + index) << '\n';
	return 0;
}