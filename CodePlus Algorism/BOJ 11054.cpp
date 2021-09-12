#include <iostream>

#define max(a,b) (a>b)?a:b

int dp_upper[1001]; //자기 자신을 포함하는 증가하는 수열 중 가장 길이가 긴 수열의 길이를 저장
int dp_lower[1001]; //뒤에서부터 자기 자신을 포함하는 증가하는 수열 중 가장 길이가 긴 수열의 길이를 저장
int dp_bitonic[1001];

int arr[1001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int arrSize;
	std::cin >> arrSize;

	for (int i = 1; i <= arrSize; i++) {
		int input;
		std::cin >> input;
		arr[i] = input;
	}

	dp_upper[1] = 1;
	for (int i = 2; i <= arrSize; i++) {
		dp_upper[i] = 1;
		for (int j = 1; j < i; j++) 
			if (arr[j] < arr[i]) dp_upper[i] = max(dp_upper[j] + 1, dp_upper[i]);
	}

	dp_lower[arrSize] = 1;
	for (int i = arrSize - 1; i >= 1; i--) {
		dp_lower[i] = 1;
		for (int j = arrSize; j > i; j--) 
			if (arr[j] < arr[i]) dp_lower[i] = max(dp_lower[j] + 1, dp_lower[i]);
	}

	for (int i = 1; i <= arrSize; i++)
		dp_bitonic[i] = dp_lower[i] + dp_upper[i] - 1;

	int answer = 0;
	for (int i = 1; i <= arrSize; i++) answer = max(answer, dp_bitonic[i]);

	std::cout << answer;
}