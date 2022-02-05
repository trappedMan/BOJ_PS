//atoi를 쓸때 들어갈 문자열은 무 조 건 끝에 \0이 있어야 한다.
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
vector<int> num;
vector<char> op;

int val(int low) {
	int ans = 0;
	while (1) {
		if (low >= op.size()) {
			for (int k = 0; k < num.size(); k++) {
				ans += num[k];
			}
			return ans;
		}
		else if (op[low++] == '-') {
			for (int k = 0; k < low; k++) {
				ans += num[k];
			}
			break;
		}
	}
	for (int i = low; i < num.size(); i++) {
		ans -= num[i];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	char tempnum[6];
	memset(tempnum, '0', 5);
	tempnum[5] = '\0';
	char temp;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		temp = str[i];
		if ('0' <= temp && temp <= '9') {
			tempnum[0] = tempnum[1];
			tempnum[1] = tempnum[2];
			tempnum[2] = tempnum[3];
			tempnum[3] = tempnum[4];
			tempnum[4] = temp;
		}
		else {
			num.push_back(atoi(tempnum));
			memset(tempnum, '0', 5);
			op.push_back(temp);
		}
	}
	num.push_back(atoi(tempnum));
	cout << val(0) << '\n';
	return 0;
}