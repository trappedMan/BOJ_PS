//devide and conquer basic
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int power(int n) {
	int sum = 1;
	for (int i = 0; i < n; i++) {
		sum *= 2;
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, r, c;
	long long int count = 0;
	cin >> N >> r >> c;
	N = power(N);
	while (N > 0) {
		if (r < N / 2) {
			if (c < N / 2) {
				;
			}
			else {
				count += (N / 2) * (N / 2);
				c -= N / 2;
			}
		}
		else {
			if (c < N / 2) {
				count += 2 * (N / 2) * (N / 2);
				r -= N / 2;
			}
			else {
				count += 3 * (N / 2) * (N / 2);
				r -= N / 2;
				c -= N / 2;
			}
		}
		N /= 2;
	}
	cout << count << '\n';
	return 0;
}