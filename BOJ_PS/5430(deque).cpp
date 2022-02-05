//using deque container(양쪽에서 삽입 및 삭제가 가능한 자료구조)
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, arraylen;
	int inputnum;
	char dummy;
	bool reverseflag = false;
	deque<int> arr;
	deque<int>::reverse_iterator iter;
	deque<int>::iterator iter2;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++) {
		reverseflag = false;
		cin >> str;
		cin >> arraylen;
		if (arraylen == 0) {
			cin >> dummy;
			cin >> dummy;
		}
		else if(arraylen>0)
			cin >> dummy;
		for (int j = 0; j < arraylen; j++) {
			cin >> inputnum;
			cin >> dummy;
			arr.push_back(inputnum);
		}
		for (int j = 0; j <= str.size(); j++) {
			if (j == str.size()) {
				cout << '[';
				if (reverseflag) {
					for (iter = arr.rbegin(); iter != arr.rend();iter++) {
						if (iter == arr.rbegin())
							cout << *iter;
						else {
							cout << ',' << *iter;
						}
					}
				}
				else {
					for (iter2 = arr.begin(); iter2 != arr.end();iter2++) {
						if (iter2 == arr.begin())
							cout << *iter2;
						else {
							cout << ',' << *iter2;
						}
					}
				}
				cout << ']' << '\n';
				break;
			}
			if (str[j] == 'R') {
				reverseflag = !reverseflag;
			}
			else {
				if (arr.empty()) {
					cout << "error\n";
					break;
				}
				else if (reverseflag) {
					arr.pop_back();
				}
				else {
					arr.pop_front();
				}
			}
		}
		arr.clear();
	}
	return 0;
}