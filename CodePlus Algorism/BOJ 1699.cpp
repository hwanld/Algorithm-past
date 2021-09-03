#include <iostream>
#include <cmath>

long long dp[100001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int min_value = 100000;
		for (int j = 1; j <= i; j++) {
			if (j * j > i) break;
			int temp = dp[i - j * j] + 1;
			if (temp < min_value) min_value = temp;
		}
		dp[i] = min_value;
	}
	std::cout << dp[n];
}

