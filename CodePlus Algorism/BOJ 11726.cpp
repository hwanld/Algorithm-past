#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	int dp[1000];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	std::cin >> n;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	std::cout << dp[n];
}
