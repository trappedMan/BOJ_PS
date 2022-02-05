#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			std::cout << '*';
		}
		std::cout << '\n';
	}
	return 0;
}