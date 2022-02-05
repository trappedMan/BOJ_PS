#define MAX_VAL 100
#include <iostream>
#include <cstdlib>

using namespace std;
char white[8][8];
char black[8][8];

int fill(char temp[][8], char** table, int i, int j) {
	int blackcount = 0, whitecount = 0;
	for (int ii = 0; ii < 8; ii++) {
		for (int jj = 0; jj < 8; jj++) {
			temp[ii][jj] = table[ii + i][jj + j];
		}
	}
	for (int ii = 0; ii < 8; ii++) {
		for (int jj = 0; jj < 8; jj++) {
			if (temp[ii][jj] != white[ii][jj])
				whitecount++;
			if (temp[ii][jj] != black[ii][jj])
				blackcount++;
		}
	}
	return whitecount > blackcount ? blackcount : whitecount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2) {
				white[i][j] = 'B';
				black[i][j] = 'W';
			}
			else {
				white[i][j] = 'W';
				black[i][j] = 'B';
			}
		}
	}
	int N, M;
	cin >> N >> M;
	char** table;
	char temp[8][8];
	table = new char* [N];
	for (int i = 0; i < N; i++) {
		*(table + i) = new char[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
		}
	}
	int min = MAX_VAL;
	int tmp;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			tmp = fill(temp, table, i, j);
			if (tmp < min) {
				min = tmp;
			}
		}
	}
	cout << min << '\n';
	for (int i = 0; i < N; i++) {
		delete[] * (table + i);
	}
	delete[] table;
	return 0;
}