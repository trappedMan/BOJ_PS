//dfs-코드 간소화 필요
#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef struct _square {
	int row, col;
	char val;
} square;
bool** isvisited;
char** grid;
int N;

bool valid(int row, int col, int val, bool RGflag = 0) {
	if (0 <= row && row < N && 0 <= col && col < N) {
		if (!RGflag||val=='B') {
			if (grid[row][col] == val)
				return true;
			else
				return false;
		}
		else {
			if (grid[row][col] == 'R'||grid[row][col]=='G')
				return true;
			else
				return false;
		}
	}
	else {
		return false;
	}
}

void dfs() {
	stack<square> st;
	square now;
	int normal = 0, RG = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isvisited[i][j]) {
				now.row = i; now.col = j;
				now.val = grid[i][j];
				st.push(now);
				isvisited[i][j] = true;
				while (!st.empty()) {
					square temp = st.top();
					int tmpy = temp.row, tmpx = temp.col, tmpval = temp.val;
					st.pop();
					isvisited[tmpy][tmpx] = true;
					if (valid(tmpy + 1, tmpx,tmpval) && !isvisited[tmpy + 1][tmpx]) {
						now.row = tmpy + 1; now.col = tmpx;
						now.val = tmpval;
						st.push(now);
					}
					if (valid(tmpy - 1, tmpx, tmpval) && !isvisited[tmpy - 1][tmpx]) {
						now.row = tmpy - 1; now.col = tmpx;
						now.val = tmpval;
						st.push(now);
					}
					if (valid(tmpy, tmpx + 1, tmpval) && !isvisited[tmpy][tmpx + 1]) {
						now.row = tmpy; now.col = tmpx + 1;
						now.val = tmpval;
						st.push(now);
					}
					if (valid(tmpy, tmpx - 1, tmpval) && !isvisited[tmpy][tmpx - 1]) {
						now.row = tmpy; now.col = tmpx - 1;
						now.val = tmpval;
						st.push(now);
					}
				}
				normal++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			isvisited[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isvisited[i][j]) {
				now.row = i; now.col = j;
				now.val = grid[i][j];
				st.push(now);
				isvisited[i][j] = true;
				while (!st.empty()) {
					square temp = st.top();
					int tmpy = temp.row, tmpx = temp.col, tmpval = temp.val;
					st.pop();
					isvisited[tmpy][tmpx] = true;
					if (valid(tmpy + 1, tmpx, tmpval, 1) && !isvisited[tmpy + 1][tmpx]) {
						now.row = tmpy + 1; now.col = tmpx;
						now.val = tmpval;
						st.push(now);
					}
					if (valid(tmpy - 1, tmpx, tmpval, 1) && !isvisited[tmpy - 1][tmpx]) {
						now.row = tmpy - 1; now.col = tmpx;
						now.val = tmpval;
						st.push(now);
					}
					if (valid(tmpy, tmpx + 1, tmpval, 1) && !isvisited[tmpy][tmpx + 1]) {
						now.row = tmpy; now.col = tmpx + 1;
						now.val = tmpval;
						st.push(now);
					}
					if (valid(tmpy, tmpx - 1, tmpval, 1) && !isvisited[tmpy][tmpx - 1]) {
						now.row = tmpy; now.col = tmpx - 1;
						now.val = tmpval;
						st.push(now);
					}
				}
				RG++;
			}
		}		
	}
	cout << normal << " " << RG << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	grid = new char* [N];
	isvisited = new bool* [N];
	for (int i = 0; i < N; i++) {
		*(grid + i) = new char[N];
		*(isvisited + i) = new bool[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			isvisited[i][j] = false;
		}
	}
	dfs();
	for (int i = 0; i < N; i++) {
		delete[] * (grid + i);
		delete[] * (isvisited + i);
	}
	delete[] isvisited;
	delete[] grid;
	return 0;
}