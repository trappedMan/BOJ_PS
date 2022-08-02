#include <bits/stdc++.h>
using namespace std;
stack<string> st;
int n, m, t, a, b;
string str1, str2;
map<string, vector<string>> name;
map<string, int> mark;
map<string, bool> visited;
int dfs() {
	for (auto s : name) {
		if (!visited.find(s.first)->second) {
			st.push(s.first);
			mark.find(s.first)->second = 0;
		}
		while (!st.empty()) {
			auto now = st.top();
			st.pop();
			if (!visited.find(now)->second) {
				visited.find(now)->second = true;
				for (auto ss : name.find(now)->second) {
					st.push(ss);
					auto& m = mark.find(ss)->second;
					if (m != -1 && m != 1 - mark.find(now)->second)
						return 0;
					if (m == -1)
						m = 1 - mark.find(now)->second;
				}
			}
		}
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> t;
	n = 1;
	while (t--) {
		cin >> m;
		name.clear(); mark.clear(); visited.clear();
		while (!st.empty()) {
			st.pop();
		}
		for (int i = 0; i < m; i++) {
			cin >> str1 >> str2;
			auto iter = name.find(str1);
			if (iter == name.end()) {
				mark.insert({ str1,-1 });
				visited.insert({ str1,0 });
				auto p = make_pair(str1, vector<string>());
				p.second.push_back(str2);
				name.insert(p);
			}
			else {
				iter->second.push_back(str2);
			}
			iter = name.find(str2);
			if (iter == name.end()) {
				mark.insert({ str2,-1 });
				visited.insert({ str2,0 });
				auto p = make_pair(str2, vector<string>());
				p.second.push_back(str1);
				name.insert(p);
			}
			else {
				iter->second.push_back(str1);
			}
		}
		int ans = dfs();
		cout << "Case #" << n << ": ";
		if (ans)
			cout << "Yes\n";
		else
			cout << "No\n";
		n++;
	}
	return 0;
}