#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int arr[1001];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + 2 * arr[i-2])%10007;
	}

	std::cout << arr[n];
}