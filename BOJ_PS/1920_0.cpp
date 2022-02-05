//binary search.
//이분 탐색 시 시행 조건을 i<=j로 유지해줘야 한다.
//최좌측값보다 더 작은 값을 찾을 때나 최우측 값보다 더 큰값을 찾을때 인덱스가 서로 뒤바뀌는 상황이 존재하기 때문
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int* A;
int bin_search(int i, int j, int val) {
	/*if (i == j) {
		if (A[i] == val)
			return 1;
		else
			return 0;
	}
	int middle = (i + j) / 2;
	if (A[middle] == val) 
		return 1;
	else if (A[middle] < val) {
		return bin_search(middle + 1, j, val);
	}
	else
		return bin_search(i, middle - 1, val);*/

	//이 조건식은 꼭 i<=j어야한다.
	while (i<=j) {
		
		if (i == j) {
			if (A[i] == val)
				return 1;
			else
				return 0;
		}
		else {
			int middle = (i + j) / 2;
			if (A[middle] == val)
				return 1;
			else if (A[middle] < val) {
				i = middle + 1;
			}
			else {
				j = middle - 1;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A,A+N);
	int M,B;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B;
		if (bin_search(0,N-1,B))
			cout << "1\n";
		else
			cout << "0\n";
	}

	delete[] A;
	return 0;
}