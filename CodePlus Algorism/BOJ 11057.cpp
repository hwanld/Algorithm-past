#include <iostream>

#define DIV 10007

long long dp[1001][10];
//n°³ÀÇ °æ¿ì, ³¡³ª´Â ÀÚ¸´¼ö°¡ 0~9±îÁö ÃÑ 10Ä­

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		long long dp_sum = 0;
		for (int j = 0; j < 10; j++) {
			dp_sum += dp[i - 1][j];
			dp_sum %= DIV;
			dp[i][j] = dp_sum;
		}
	}
	long long answer = 0;
	for (int i = 0; i < 10; i++) answer += dp[n][i];
	answer %= DIV;
	std::cout << answer;
}