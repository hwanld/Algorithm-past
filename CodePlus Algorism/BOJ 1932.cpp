#include <iostream>

int value[501][501];
int dp[501][501];

int max(int a, int b);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int numTriangle;
	std::cin >> numTriangle;

	for (int i = 1; i <= numTriangle; i++) {
		for (int j = 1; j <= i; j++) {
			int input;
			std::cin >> input;
			value[i][j] = input;
		}
	}
	if (numTriangle == 1) std::cout << value[1][1];
	else if (numTriangle == 2) std::cout << max(value[2][1], value[2][2])+value[1][1];
	else {
		dp[1][1] = value[1][1];
		dp[2][1] = dp[1][1] + value[2][1];
		dp[2][2] = dp[1][1] + value[2][2];

		for (int i = 3; i <= numTriangle; i++) {
			for (int j = 1; j <= i; j++) {
				if (j == 1) dp[i][j] = dp[i - 1][j] + value[i][j];
				else if (j == i) dp[i][j] = dp[i - 1][j - 1] + value[i][j];
				else 
					dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + value[i][j];
			}
		}
		int answer = 0;
		for (int i = 1; i <= numTriangle; i++) 
			if (dp[numTriangle][i] > answer)answer = dp[numTriangle][i];
		std::cout << answer;
	}
}

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}