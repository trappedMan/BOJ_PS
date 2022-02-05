//최적화 실패. 
//기본적으로 이런 자리수 체크할 때 자리수가 작은쪽부터 체크해서 %10과 /10을 반복하면 더 빠르게 할수 있다

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool is_six(int N) {
	int MSD = 100000000;
	int sequentsix = 0;
	while (!(N / MSD)) {
		MSD /= 10;
	}
	while (MSD!=0) {
		if ((N / MSD) % 10 == 6) {
			sequentsix++;
		}
		else
			sequentsix = 0;

		if (sequentsix == 3)
			return true;
		MSD /= 10;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int count = 0;
	int i = 665;
	cin >> N;
	while (count!=N) {
		if (is_six(i))
			count++;
		i++;
	}
	cout << --i << '\n';
	return 0;
}