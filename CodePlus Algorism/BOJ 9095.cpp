#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector <int> inputVector;
	for (int i = 0; i < n; i++) {
		int input;
		std::cin >> input;
		inputVector.push_back(input);
	}
	int dp[12];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	for (int i = 0; i < n; i++) 
		std::cout << dp[inputVector[i]]<<"\n";
}