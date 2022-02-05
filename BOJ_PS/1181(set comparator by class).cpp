//class 내에서 오버로딩한 연산자를 이용해 set의 정렬 기준 설정
#include <iostream>
#include <set>
using namespace std;
class comp {
public:
	bool operator()(const string &a,const string& b) const {
		if (a.length() == b.length())
			return a < b;
		else {
			return a.length() < b.length();
		}

	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	set<string,comp> strset;
	set<string>::iterator iter;
	string str;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		strset.insert(str);
	}
	for (iter = strset.begin(); iter != strset.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}