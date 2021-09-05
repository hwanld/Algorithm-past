#include <iostream>

int costArr[1001][4];
//1000���� ��, 3���� ��
long long dp[1001][4];
//1000���� ���� ���� R,G,B�� ������ ����� ���� �ּ� cost DP

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

	//���� ������ 1���� ����� ���� dp�� ����
	dp[1][1] = costArr[1][1];
	dp[1][2] = costArr[1][2];
	dp[1][3] = costArr[1][3];

	for (int i = 2; i <= numHouse; i++) {
		for (int j = 1; j <= 3; j++) {
			long long minDPbefore;
			//index�� i�϶� ������ ���� 1�� ���;�տ� �� �� �ִ� ���� 2�Ǵ�3 
			if (j == 1) {
				if (dp[i - 1][2] > dp[i - 1][3]) minDPbefore = dp[i - 1][3];
				else minDPbefore = dp[i - 1][2];
			}
			//index�� i�϶� ������ ���� 2�� ���;�տ� �� �� �ִ� ���� 1�Ǵ�3
			else if (j == 2) {
				if (dp[i - 1][1] > dp[i - 1][3]) minDPbefore = dp[i - 1][3];
				else minDPbefore = dp[i - 1][1];
			}
			//index�� i�϶� ������ ���� 3�� ���;�տ� �� �� �ִ� ���� 1�Ǵ�2
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