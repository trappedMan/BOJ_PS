#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, sum = 0;
	int min, max, cover, median;
	double avg;
	int* freq = new int[8001];
	for (int i = 0; i <= 8000; i++) {
		freq[i] = 0;
	}
	int maxfreq, maxfreqidx;
	cin >> N;
	int* val = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> val[i];
		sum += val[i];
		freq[val[i] + 4000]++;
	}

	avg = sum / (double)N;
	sort(val, val + N);
	median = val[N / 2];
	for (int i = 0; i <= 8000; i++) {
		if (freq[i]) {
			min = i;
			break;
		}
	}
	for (int i = 8000; i >= 0; i--) {
		if (freq[i]) {
			max = i;
			break;
		}
	}
	cover = max - min;

	maxfreq = freq[8000];
	maxfreqidx = 8000;
	for (int i = 7999; i >=0; i--) {
		if (maxfreq <= freq[i]) {
			maxfreq = freq[i];
			maxfreqidx = i;
		}
	}
	for (int i = maxfreqidx + 1; i <=8000; i++) {
		if (maxfreq == freq[i]) {
			maxfreqidx = i;
			break;
		}
	}
	cout << fixed;
	cout.precision(0);
	cout << avg << '\n';
	cout.unsetf(ios::fixed);
	cout << median << '\n';
	cout << maxfreqidx-4000 << '\n';
	cout << cover << '\n';
	delete[] freq;
	delete[] val;
	return 0;
}