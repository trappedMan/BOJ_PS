#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
tuple<int, int, int> _3elem[8] = { {0,1,3},{0,1,2},{0,4,2},{0,4,3},{5,1,3},{5,1,2},{5,4,3},{5,4,2} };
pair<int, int> _2elem[12] = { {0,1},{0,2},{0,3},{0,4},{1,3},{3,4},{4,2},{1,2},{5,1},{5,2},{5,3},{5,4} };
ll n, _3min, _2min, _1min;
ll d[6];
void func() {
	_1min = d[0];
	for (int i = 0; i < 6; i++)
		_1min = min(_1min, d[i]);
	_2min = 101;
	for (int i = 0; i < 12; i++) {
		auto t = _2elem[i];
		_2min = min(_2min, d[t.first] + d[t.second]);
	}
	_3min = 151;
	for (int i = 0; i < 8; i++) {
		auto t = _3elem[i];
		_3min = min(_3min, d[get<0>(t)] + d[get<1>(t)] + d[get<2>(t)]);
	}
}
int main()
{
	FAST;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < 6; i++)
		cin >> d[i];
	if (n == 1) {
		sort(d, d + 6);
		sum = d[0] + d[1] + d[2] + d[3] + d[4];
		cout << sum;
		return 0;
	}
	func();
	//윗면 
	sum += 4 * _3min + 4 * (n - 2) * _2min + (n - 2) * (n - 2) * _1min;
	//윗면을 제외한 n-1개의 면
	sum += (n - 1) * ((4 * _2min) + 4 * (n - 2) * _1min);
	cout << sum;
	return 0;
}