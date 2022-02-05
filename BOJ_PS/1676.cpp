#include <iostream>
using namespace std;
int twocount, fivecount;
void count(int i) {
	int j;
	for (j=i;j%2==0;j/=2) {
		twocount++;
	}
	for (int k = j; k % 5 == 0; k /= 5) {
		fivecount++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	twocount = 0; fivecount = 0;
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		count(i);
	}
	int val = twocount > fivecount ? fivecount : twocount;
	cout << val << '\n';
	return 0;
}