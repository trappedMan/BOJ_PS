#include <iostream>
#include <algorithm>
using namespace std;
//내림차순
int Comp(const void* a, const void* b) {
	if (*(int*)a == *(int*)b)
		return 0;
	else if (*(int*)a > *(int*)b)
		return 1;
	else
		return -1;
}
//오름차순
int Comp2(const void* a, const void* b) {
	if (*(int*)a == *(int*)b)
		return 0;
	else if (*(int*)a < *(int*)b)
		return 1;
	else
		return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int* A, *B;
	cin >> N;
	A = new int[N];
	B = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	qsort(A, N, sizeof(int), Comp);
	qsort(B, N, sizeof(int), Comp2);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}
	cout << sum << '\n';
	delete[] A;
	delete[] B;
	return 0;
}