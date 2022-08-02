#include <bits/stdc++.h>
using namespace std;
map<int, int> card;
int n, m, test[500000];
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		auto iter = card.find(tmp);
		if (iter == card.end()) {
			card.insert({ tmp,1 });
		}
		else {
			(iter->second)++;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> test[i];
	}
	for (int i = 0; i < m; i++) {
		auto iter = card.find(test[i]);
		if (iter == card.end()) {
			cout << 0;
		}
		else {
			cout << iter->second;
		}
		cout << " ";
	}
	return 0;
}