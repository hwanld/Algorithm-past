#include <iostream>

#define DIV 1000000000

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	long long answerarr[201][201]; 
	
	for (int i = 1; i <= k; i++) {
		answerarr[1][i] = i;
	}
	for (int i = 1; i <= n; i++) {
		answerarr[i][1] = 1;
		answerarr[i][2] = i + 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 3; j <= k; j++) {
			long long answer = 0;
			for (int s = 1; s <= j; s++) answer += answerarr[i - 1][s];
			answerarr[i][j] = answer % DIV;
		}
	}

	std::cout << answerarr[n][k] % DIV;
}