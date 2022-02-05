//stack
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	stack<int> st;
	int N;
	cin >> N;
	int now;
	int j = 1;
	vector<char> p;
	vector<char>::iterator iter;
	for (;!(st.empty()&&j>N);) {
		if (st.empty()) {
			st.push(j++);
			p.push_back('+');
		}
		cin >> now;
		if (now < st.top()) {
			cout << "NO\n";
			return 0;
		}
		while (now > st.top()) {
			st.push(j++);
			p.push_back('+');
		}
		st.pop();
		p.push_back('-');
	}
	for (iter = p.begin(); iter != p.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}