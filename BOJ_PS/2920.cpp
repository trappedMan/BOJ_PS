#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int num[8];
	int flag;
	for (int i = 0; i < 8; i++) {
		cin >> num[i];
	}
	if (num[0] < num[1])
		flag = -1;
	else if (num[0] > num[1])
		flag = 1;

	for (int i = 1; i < 7; i++) {
		if (flag == 1) {
			if (num[i] > num[i + 1])
				continue;
			else {
				flag = 0;
				break;
			}
		}
		else if (flag == -1) {
			if (num[i] < num[i + 1])
				continue;
			else {
				flag = 0;
				break;
			}
		}
	}
	if (flag == 1)
		cout << "descending\n";
	else if (flag == -1)
		cout << "ascending\n";
	else
		cout << "mixed\n";

	return 0;
}