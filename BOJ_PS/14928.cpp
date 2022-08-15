#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> str;
	int result = 0;
	for (int i = 0; i < str.length(); i++) {
		result = ((result * 10) % 20000303 + (str[i] - '0')) % 20000303;
	}
	cout << result;
}
//이해하기 위해 152를 11로 나눈 나머지를 이 로직으로 푼다고 생각해보자.
//결국 (150%11+2)%11이 되는데 이건 (40%11+2)%11이랑 같은 결과. 이걸 확장