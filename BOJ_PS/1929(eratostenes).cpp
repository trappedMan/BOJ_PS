//eratos
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int start, end;
	cin >> start >> end;
	bool* prime = new bool[end + 1];
	for (int i = 0; i <= end; i++) {
		prime[i] = true;
	}
	int i = 2;
	if (end >= 1)
		prime[1] = false;
	while (1) {
		if (prime[i] && i * i <= end) {
			for (int j = 2 * i; j <= end; j += i) {
				prime[j] = false;
			}
		}
		i++;
		if (i * i > end)
			break;
	}
	for (int i = start; i <= end; i++) {
		if (prime[i] == true)
			cout << i << '\n';
	}
	return 0;
}