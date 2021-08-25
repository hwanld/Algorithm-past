#include <iostream>

#define DIV 1000000000
long long numarr[101][10]; //101은 계단수의 자릿수, 10은 끝자리가 0~9의 경우

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	numarr[1][0] = 0;

	for (int i = 1; i < 10; i++) 
		numarr[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				numarr[i][j] = numarr[i - 1][j + 1] % DIV;
			}
			else if (j == 9) {
				numarr[i][j] = numarr[i - 1][j - 1] % DIV;
			}
			else {
				numarr[i][j] = (numarr[i - 1][j - 1] + numarr[i - 1][j + 1]) % DIV;
			}
		}
	}

	long long sum = 0;

	for (int i = 0; i < 10; i++) 
		sum += numarr[n][i];

	std::cout << sum % DIV;
}