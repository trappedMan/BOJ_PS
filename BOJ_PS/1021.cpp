#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
deque<int> a;
int main()
{
	FAST;
	int n, m, t, pos = 0, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		a.push_back(i + 1);
	for (int i = 0; i < m; i++) {
		cin >> t;
		pos = 0;
		for (const auto& aa : a) {
			if (aa != t)
				++pos;
			else
				break;
		}
		if (pos == 0)
			a.pop_front();
		else if (pos <= a.size() / 2) {
			while (a.front() != t) {
				int tmp = a.front();
				a.pop_front();
				a.push_back(tmp);
				++ans;
			}
			a.pop_front();
		}
		else {
			while (a.back() != t) {
				int tmp = a.back();
				a.pop_back();
				a.push_front(tmp);
				++ans;
			}
			a.pop_back();
			++ans;
		}
	}
	cout << ans;
	return 0;
}