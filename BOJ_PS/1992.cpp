//devide-and-conquer basic
#include <iostream>
#include <string>
using namespace std;
char** image;
bool all_same(int startrow, int startcol, int lastrow, int lastcol) {
	char val = image[startrow][startcol];
	for (int i = startrow; i < lastrow; i++) {
		for (int j = startcol; j < lastcol; j++) {
			if (image[i][j] != val)
				return false;
		}
	}
	return true;
}

void quadtree(int startrow, int startcol, int lastrow, int lastcol) {
	if (all_same(startrow, startcol, lastrow, lastcol)) {
		cout << image[startrow][startcol];
		return;
	}
	cout << '(';
	int size = lastrow - startrow;
	size /= 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			quadtree(startrow + i * size, startcol + j * size, startrow + (i + 1) * size
				, startcol + (j + 1) * size);
		}
	}
	
	cout << ')';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	string str;
	cin >> N;
	if (N == 1) {
		cin >> N;
		cout << N << '\n';
		return 0;
	}
	image = new char* [N];
	for (int i = 0; i < N; i++) {
		*(image + i) = new char[N];
	}
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			image[i][j] = str.at(j);
		}
	}
	quadtree(0, 0, N, N);
	for (int i = 0; i < N; i++) {
		delete[] * (image + i);
	}
	delete[] image;
	return 0;
}