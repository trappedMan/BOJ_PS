#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int num[10];
	int mod[42];
	for (int i = 0; i < 42; i++)
		mod[i] = 0;
	for (int i = 0; i < 10; i++)
		cin >> num[i];
	for (int i = 0; i < 10; i++) {
		mod[num[i] % 42] = 1;
	}
	int count = 0;
	for (int i = 0; i < 42; i++) {
		if (mod[i])
			count++;
	}
	cout << count << '\n';
	return 0;
}