#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	getline(cin, str);
	char* a = new char[str.size()];
	int sum = 0;
	strcpy(a, str.c_str());
	if (a[0] != ' ' && strlen(a) != 0)
		sum++;
	for (int i = 1; i < strlen(a); i++) {
		if (a[i - 1] == ' ' && a[i] != ' ')
			sum++;
	}
	cout << sum << '\n';
	return 0;
}