//hasing- set
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	set<string> s;
	vector<string> res;
	string str;
	int N, M;
	int db = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (s.find(str) != s.end()) {
			db++;
			res.push_back(str);
		}
	}
	sort(res.begin(), res.end());
	cout << db << '\n';
	for (auto iter : res) {
		cout << iter << '\n';
	}
	return 0;
}