#include <iostream>

#define max(a,b) (a>b)?a:b

int arr[1001];
int dp[1001];
//dp[n]�� n�� �����ϴ� ��� �� ���� ���̰� �����ϴ� ������ ����

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int sequenceSize;
	std::cin >> sequenceSize;
	for (int i = 1; i <= sequenceSize; i++) {
		int input;
		std::cin >> input;
		arr[i] = input;
	}
	dp[1] = 1;
	for (int i = 2; i <= sequenceSize; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) 
			if (arr[j] > arr[i]) dp[i] = max(dp[i], dp[j] + 1);
	}
	int answer = 0;
	for (int i = 1; i <= sequenceSize; i++) 
		answer = max(answer, dp[i]);
	std::cout << answer;
}