//devide-and-conquer
#define INVALID -100
#include <iostream>
#include <string>
using namespace std;
int neg, zero, pos;
int** paper;
bool all_same(int startrow,int startcol,int lastrow,int lastcol) {
	int val = paper[startrow][startcol];
	for (int i = startrow; i < lastrow; i++) {
		for (int j = startcol; j < lastcol; j++) {
			if (paper[i][j] != val) {
				val = INVALID;
				break;
			}
		}
	}
	switch (val) {
	case -1:
		neg++;
		break;
	case 0:
		zero++;		
		break;
	case 1:
		pos++;
		break;
	case INVALID:
		return false;
	}
	return true;
}
void Calc_Paper(int startrow,int startcol,int lastrow,int lastcol) {
	if (all_same(startrow,startcol,lastrow,lastcol))
		return;
	int size = lastrow - startrow;
	size /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Calc_Paper(startrow + size * i, startcol + size * j, startrow + size * (i + 1), startcol + size * (j + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	neg = zero = pos = 0;
	int N;
	cin >> N;
	paper = new int* [N];
	for (int i = 0; i < N; i++) {
		*(paper + i) = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	Calc_Paper(0,0,N,N);
	cout << neg << '\n';
	cout << zero << '\n';
	cout << pos << '\n';
	for (int i = 0; i < N; i++) {
		delete[] * (paper + i);
	}
	delete[] paper;
	return 0;
}