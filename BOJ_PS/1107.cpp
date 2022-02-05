#include <iostream>
using namespace std;
int ruined[10];

int is_able_once(int num) {
	int count = 0;
	if (num <= 0) {
		if (ruined[0])
			return 0;
		else
			return 1;
	}
	else {
		for (int i = num; i > 0; i /= 10) {
			if (ruined[i % 10])
				return 0;
			else
				count++;
		}
		return count;
	}
}

int calc(int channel,int n_ruined) {
	int plusminus = 0, numbering = 500000;
	int nowabove = channel, nowbelow = channel;
	int tmp,tmp2;
	//Case 1: +,-만 사용해서 채널을 바꿀 때
	if (channel > 100)
		plusminus = channel - 100;
	else
		plusminus = 100 - channel;

	if (n_ruined == 10)
		return plusminus;
	//Case 2: 숫자 버튼을 포함해서 채널을 바꿀 때
	while (1) {
		tmp = is_able_once(nowabove);
		if (tmp) {
			numbering = tmp + (nowabove - channel);
			tmp2 = is_able_once(nowbelow);
			if (tmp2 && numbering > tmp2 + (channel - nowbelow)) {
				numbering = tmp2 + (channel - nowbelow);
			}
			break;
		}
		tmp = is_able_once(nowbelow);
		if (tmp) {
			numbering = tmp + (channel - nowbelow);
			tmp2 = is_able_once(nowabove);
			if (tmp2 && numbering > tmp2 + (nowabove - channel)) {
				numbering = tmp2 + (nowabove - channel);
			}
			break;
		}
		nowabove++; nowbelow--;
	}
	return plusminus > numbering ? numbering : plusminus;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int channel, n_ruined, temp;
	for (int i = 0; i < 10; i++) {
		ruined[i] = 0;
	}
	cin >> channel;
	cin >> n_ruined;
	for (int i = 0; i < n_ruined; i++) {
		cin >> temp;
		ruined[temp] = 1;
	}
	cout << calc(channel,n_ruined) << '\n';
	return 0;
}