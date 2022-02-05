#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	float Max;
	float* score;
	cin >> N;
	score = new float[N];

	if (N >= 1) {
		cin >> score[0];
		Max = score[0];
	}
		
	for (int i = 1; i < N; i++) {
		cin >> score[i];
		if (score[i] > Max)
			Max = score[i];
	}
	float sum = 0;
	for (int i = 0; i < N; i++) {
		score[i] = 100 * score[i] / Max;
		sum += score[i];
	}
	float avg = sum / N;
	cout.precision(6);
	cout << avg << '\n';
	return 0;
}