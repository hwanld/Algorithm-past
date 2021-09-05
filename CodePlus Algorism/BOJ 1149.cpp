#include <iostream>

int costArr[1001][4];
//1000개의 집, 3개의 색
long long dp[1001][4];
//1000개의 집이 각각 R,G,B로 끝나는 경우의 가장 최소 cost DP

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int numHouse;
	std::cin >> numHouse;

	for (int i = 1; i <= numHouse; i++) {
		for (int j = 1; j <= 3; j++) {
			int input;
			std::cin >> input;
			costArr[i][j] = input;
		}
	}

	//집의 갯수가 1개인 경우일 때의 dp를 설정
	dp[1][1] = costArr[1][1];
	dp[1][2] = costArr[1][2];
	dp[1][3] = costArr[1][3];

	for (int i = 2; i <= numHouse; i++) {
		for (int j = 1; j <= 3; j++) {
			long long minDPbefore;
			//index가 i일때 마지막 색이 1인 경우;앞에 올 수 있는 색은 2또는3 
			if (j == 1) {
				if (dp[i - 1][2] > dp[i - 1][3]) minDPbefore = dp[i - 1][3];
				else minDPbefore = dp[i - 1][2];
			}
			//index가 i일때 마지막 색이 2인 경우;앞에 올 수 있는 색은 1또는3
			else if (j == 2) {
				if (dp[i - 1][1] > dp[i - 1][3]) minDPbefore = dp[i - 1][3];
				else minDPbefore = dp[i - 1][1];
			}
			//index가 i일때 마지막 색이 3인 경우;앞에 올 수 있는 색은 1또는2
			else if (j == 3) {
				if (dp[i - 1][1] > dp[i - 1][2]) minDPbefore = dp[i - 1][2];
				else minDPbefore = dp[i - 1][1];
			}
			dp[i][j] = minDPbefore + costArr[i][j];
		}
	}
	
	int answer = dp[numHouse][1];
	for (int i = 1; i <= 3; i++) 
		if (dp[numHouse][i] < answer) answer = dp[numHouse][i];
	
	std::cout << answer;
}