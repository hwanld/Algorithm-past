#include <iostream>

int dp[31];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i+=2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j-=2)
			dp[i] += 2 * dp[j];
	}

	std::cout << dp[n];
}
