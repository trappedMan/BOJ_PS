#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int num[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 5; i++) {
		sum += num[i] * num[i];
	}
	cout << sum % 10 << '\n';
	return 0;
}