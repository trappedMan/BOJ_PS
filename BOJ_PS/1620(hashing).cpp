#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	string str;
	int idx;
	cin >> N >> M;
	vector<string> dogam;
	vector<vector<pair<int, string>>> hash;
	vector<pair<int, string>>::iterator iter;
	hash.reserve(100000);
	hash.resize(100000);
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		cin >> str;
		dogam.push_back(str);
		for (int j = 0; j < str.size(); j++) {
			temp += str[j];
		}
		hash[temp].push_back(make_pair(i,str));
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		if ('0' <= str[0] && str[0] <= '9') {
			idx = atoi(str.c_str());
			cout << dogam.at(idx-1) << '\n';
		}
		else {
			int temp = 0;
			for (int j = 0; j < str.size(); j++) {
				temp += str[j];
			}
			for (iter = hash[temp].begin(); iter != hash[temp].end(); iter++) {
				if (iter->second == str) {
					cout << iter->first << '\n';
					break;
				}
			}
		}
	}
	return 0;
}