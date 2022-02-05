//binary search
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int maxval;
int K, N;
int count_lan(long long int* lan,int tempmax) {
	long long int count = 0;
	for (int i = 0; i < K; i++) {
		count += lan[i] / tempmax;
	}
	if (count >= N)
		return 1;
	else
		return -1;
}
int find_val(long long int* lan,long long int i,long long int j) {
	int comp;
	comp= count_lan(lan, (i + j) / 2);
	if (i == j) {
		if (comp == -1)
			return --i;
		return i;
	}
	if (comp == 1) {
		return find_val(lan, (i + j) / 2 + 1, j);
	}
	else {
		return find_val(lan, i, (i + j) / 2);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long int* lan;
	cin >> K >> N;
	lan = new long long int[K];
	for (int T = 0; T < K; T++) {
		cin >> lan[T];
	}
	maxval = lan[0];
	for (int i = 1; i < K; i++) {
		if (maxval < lan[i]) {
			maxval = lan[i];
		}
	}
	cout << find_val(lan,1,maxval) << '\n';
	delete[] lan;
	return 0;
}