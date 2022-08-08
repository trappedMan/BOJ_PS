#include <bits/stdc++.h>
using namespace std;
int v[100001];
int back[100001];
vector<int> ans;
queue<pair<int,int>> q;
int n, k, cnt;
inline bool valid(int i) { return 0 <= i && i <= 100000; }
int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	if (n == k) {
		cout << 0 << '\n' << n;
		return 0;
	}
	q.push({ n,1});
	while (!q.empty()) {
		auto a = q.front();
		q.pop();
		if (a.first == k)
			break;
		if (valid(a.first - 1)&&!v[a.first-1]) {
			back[a.first - 1] = a.first;
			v[a.first - 1] = a.second + 1;
			q.push({ a.first - 1,a.second + 1 });
		}
		if (valid(a.first + 1) && !v[a.first + 1]) {
			back[a.first + 1] = a.first;
			v[a.first + 1] = a.second + 1;
			q.push({ a.first + 1,a.second + 1 });
		}
		if (valid(a.first * 2) && !v[a.first * 2]) {
			back[a.first * 2] = a.first;
			v[a.first * 2] = a.second + 1;
			q.push({ a.first * 2,a.second + 1});
		}
	}
	cout << v[k] - 1 << '\n';
	ans.push_back(k);
	while (k!=n) {
		ans.push_back(back[k]);
		k = back[k];
	}
	reverse(ans.begin(), ans.end());
	for (const auto& s : ans)
		cout << s << ' ';
	return 0;
}