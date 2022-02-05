#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int mul = 6;
	cin >> N;
	if (N == 1) {
		cout << 1 << '\n';
		return 0;
	}
	int i, j, count = 1;
	for (i = 2; i <= N; ) {
		count++;
		for (j = i; j < i + mul; j++) {
			if (j == N) {
				cout << count << '\n';
				return 0;
			}
		}
		mul += 6;
		i = j;
	}
	cout << count << '\n';
	return 0;
}