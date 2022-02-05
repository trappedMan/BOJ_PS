#include <iostream>
using namespace std;
int fourmin(int x,int y,int z,int w) {
	int a[4] = { x,y,z,w };
	int min = a[0];
	for (int i = 1; i < 4; i++) {
		if (min > a[i])
			min = a[i];
	}
	return min;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int min = fourmin(x, y, w - x, h - y);
	cout << min << '\n';
	return 0;
}