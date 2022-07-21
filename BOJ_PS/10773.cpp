#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	FAST;
	int n, tmp, sum = 0;
	cin >> n;
	stack<int> st;
	while (n--) {
		cin >> tmp;
		if (!tmp)
			st.pop();
		else
			st.push(tmp);
	}
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return 0;
}