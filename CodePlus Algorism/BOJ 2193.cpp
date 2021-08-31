#include <iostream>

long long dp[91][2];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	long long answer = dp[n][0] + dp[n][1];

	std::cout << answer;
}