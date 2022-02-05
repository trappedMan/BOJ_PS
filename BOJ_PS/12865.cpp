//knapsack problem
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	int* W, * V;
	int** table;
	table = new int* [N + 1];
	for (int i = 0; i < N + 1; i++) {
		*(table + i) = new int[K + 1];
	}
	W = new int[N + 1];
	V = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			table[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (W[i] > j) {
				table[i][j] = table[i - 1][j];
			}
			else if (table[i - 1][j] > V[i] + table[i-1][j - W[i]]) {
				table[i][j] = table[i - 1][j];
			}
			else {
				table[i][j] = V[i] + table[i - 1][j - W[i]];
			}
		}
	}
	/*for (int i = 1; i <= N; i++) {
		cout << W[i] << " ";
	}
	cout << '\n';
	for (int j = 1; j <= N; j++) {
		cout << V[j] << " ";
	}
	cout << '\n';
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			cout << table[i][j] << " ";
		}
		cout << '\n';
	}*/
	cout << table[N][K] << '\n';
	for (int i = 0; i < N + 1; i++) {
		delete[] * (table + i);
	}
	delete[] table;
	delete[] W;
	delete[] V;
	return 0;
}