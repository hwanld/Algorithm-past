#include <iostream>

#define DIV 9901

long long arr[100001][3];
//100000가지의 경우에 대해서, 각각 1.좌 2.우 3.없음 으로 2차원 배열 생성 
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	arr[1][0] = 1;
	arr[1][1] = 1;
	arr[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i][0] = (arr[i - 1][2] + arr[i - 1][1]) % DIV;
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][0]) % DIV ;
		arr[i][2] = (arr[i - 1][2] + arr[i - 1][1] + arr[i - 1][0]) % DIV;
	}

	int sum = (arr[n][0] + arr[n][1] + arr[n][2]) % DIV;

	std::cout << sum;
}