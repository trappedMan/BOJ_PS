#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	FAST;
	int n, a, b;
	cin >> n;
	vector<int> rank;
	rank.resize(50);
	for (int i = 0; i < 50; i++) {
		rank[i] = 1;
	}
	vector<pair<int, int>> dung;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		dung.push_back(make_pair(a,b));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dung[i].first < dung[j].first && dung[i].second < dung[j].second) {
				rank[i]++;
			}
		}
		cout << rank[i] << ' ';
	}
	return 0;
}