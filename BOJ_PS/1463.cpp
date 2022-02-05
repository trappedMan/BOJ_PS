//dynamic programming
#define Max 1000001
#include <iostream>

using namespace std;
int search(int* min,int N) {
	int val;
	min[0] = min[1] = 0;
	for (int i = 2; i <= N; i++) {
		val = Max;
		if (i % 3==0) {
			if (val > min[i / 3] + 1) {
				val = min[i / 3] + 1;
			}
		}
		if (i % 2==0) {
			if (val > min[i / 2] + 1) {
				val = min[i / 2] + 1;
			}
		}
		if (val > min[i - 1] + 1) {
			val = min[i - 1] + 1;
		}
		min[i] = val;
	}
	return min[N];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int* min = new int[N + 1];
	cout << search(min, N) << '\n';
	delete[] min;
	return 0;
}