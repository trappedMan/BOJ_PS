#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string num;
	int size, flag;
	while (1) {
		flag = 1;
		cin >> num;
		size = num.size();
		if (num == "0")
			break;
		for (int i = 0; i < size/2; i++) {
			if (num[i] != num[size - 1 - i])
				flag = 0;
		}
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}