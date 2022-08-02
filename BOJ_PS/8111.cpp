#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;
pair<int, int> p[20001];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t; 
	cin >> t; 
	while (t--) {
		int n, cur, nxt;
		cin >> n;
		const int num = 10 % n;
		queue<int> q;
		q.push(1);
		memset(p, 0, sizeof(pair<int, int>) * 20001);
		p[1] = { -1, -1 };
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (cur == 0) break;
			nxt = (cur * num) % n;
			if (!p[nxt].first) {
				p[nxt] = make_pair(cur, '0');
				q.push(nxt);
			}
			nxt = (cur * num + 1) % n;
			if (!p[nxt].first) {
				p[nxt] = make_pair(cur, '1');
				q.push(nxt);
			}
			
		}
		string ans;
		for (auto i = p[0]; i.first != -1; i = p[i.first]) {
			ans = ans + (char)i.second;
		}
		ans = ans + '1';
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}