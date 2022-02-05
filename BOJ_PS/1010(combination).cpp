//조합을 코드로 작성할 때는
//m!/(m-n)!*n!에 대하여 m-n과 n 중에 큰 쪽을 기준으로 미리 m!을 나눠주고 시작해야 범위를 안벗어날것
#include <iostream>
using namespace std;
unsigned long long int fact(int n,int low) {
	if (n == 0)
		return 1;
	unsigned long long int factval = 1;
	while (n > low) {
		factval *= n;
		n--;
	}
	return factval;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int n, m;
		cin >> n >> m;
		unsigned long long int value;
		if (n >= m - n)
			value = fact(m, n) / fact(m - n, 1);
		else
			value = fact(m, m-n) / fact(n, 1);
		cout << value << '\n';
	}
	return 0;
}