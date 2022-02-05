#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	double a, b;
	cin >> a >> b;
	cout.precision(10);
	cout << a / b;
	return 0;
}