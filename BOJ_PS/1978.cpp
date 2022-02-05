#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, count = 0;
	int tmp;
	bool prime[1001];
	for (int i = 0; i <= 1000; i++) {
		prime[i] = true;
	}
	//eratostenes algorithm
	prime[1] = false;
	int i = 2;
	while (i * i <= 1000) {
		if (prime[i]) {
			for (int j = 2 * i; j <= 1000; j += i) {
				prime[j] = false;
			}
		}
		i++;
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (prime[tmp])
			count++;
	}
	cout << count << '\n';
	return 0;
}