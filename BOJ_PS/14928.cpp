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
//�����ϱ� ���� 152�� 11�� ���� �������� �� �������� Ǭ�ٰ� �����غ���.
//�ᱹ (150%11+2)%11�� �Ǵµ� �̰� (40%11+2)%11�̶� ���� ���. �̰� Ȯ��