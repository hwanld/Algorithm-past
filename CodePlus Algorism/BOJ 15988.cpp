#include <iostream>
#include <vector>

#define DIV 1000000009


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector <long long> v;
	int max_input = 0;
	for (int i = 0; i < n; i++) {
		int input;
		std::cin >> input;
		v.push_back(input);
		if (max_input < input)
			max_input = input;
	}

	long long* dp = new long long[max_input+1];

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= max_input; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % DIV;
	}

	for (int i = 0; i < n; i++) {
		std::cout << dp[v[i]]<<"\n";
	}
}