#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int val;
	cin >> val;
	int sum, i;
	for (i = 0; i <= val; i++) {
		sum = 0;
		sum += i;
		for (int j = i; !(j / 10 == 0 && j % 10 == 0); j /= 10) {
			sum += j % 10;;
		}
		if (sum == val) {
			cout << i << '\n';
			return 0;
		}
	}
	if (i == val + 1)
		cout << "0\n";
	return 0;
}