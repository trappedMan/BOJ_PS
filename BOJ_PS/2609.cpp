#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	int divisor, dividend, remainder;
	dividend = a;
	divisor = b;
	while (dividend % divisor != 0) {
		remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}
	cout << divisor << '\n';
	cout << a * b / divisor << '\n';
	return 0;
}