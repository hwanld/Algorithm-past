#include <iostream>
#include <vector>

int dp[10001][3];
//0 안 마시는 것 1 처음 마시는 것 2 두번째 마시는 것

int max_3(int a, int b, int c);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int numOfGlass;
	std::cin >> numOfGlass;
	std::vector <int> amountOfGlass;
	amountOfGlass.push_back(0);

	for (int i = 0; i < numOfGlass; i++) {
		int input;
		std::cin >> input;
		amountOfGlass.push_back(input);
	}

	if (numOfGlass == 1) std::cout << amountOfGlass[1];
	else if (numOfGlass == 2) std::cout << amountOfGlass[1] + amountOfGlass[2];
	else {
		dp[1][0] = 0;
		dp[1][1] = amountOfGlass[1];
		dp[1][2] = amountOfGlass[1];
		dp[2][0] = dp[1][1];
		dp[2][1] = amountOfGlass[2];
		dp[2][2] = dp[1][1] + amountOfGlass[2];

		for (int i = 3; i <= numOfGlass; i++) {
			dp[i][0] = max_3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = dp[i - 1][0] + amountOfGlass[i];
			dp[i][2] = dp[i - 1][1] + amountOfGlass[i];
		}

		int answer = max_3(dp[numOfGlass][0], dp[numOfGlass][1], dp[numOfGlass][2]);
		std::cout << answer;
	}
}

int max_3(int a, int b, int c) {
	if (a >= b && a >= c) return a;
	else if (b >= a && b >= c) return b;
	else return c;
}