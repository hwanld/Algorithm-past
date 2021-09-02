#include <iostream>
#include <vector>

int arr[100001];
long long dp[100001];
long long max(long long a, long long b);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int input;
		std::cin >> input;
		arr[i] = input;
	}
	
	
	dp[1] = arr[1];
	long long max_dp = dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1]+arr[i], arr[i]);
		if (dp[i] > max_dp) max_dp = dp[i];
	}

	std::cout << max_dp;
}
long long max(long long a, long long b) {
	if (a > b) return a;
	else return b;
}