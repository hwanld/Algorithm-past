#include <iostream>
#include <vector>

#define MOD 1000000009
#define LIMIT 100000

long long d[100001][4];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	d[1][1] = d[2][2] = d[3][3] = 1;
	d[3][1] = d[3][2] = 1;

	for (int i = 4; i <= LIMIT; i++) {
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % MOD;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % MOD;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % MOD;
	}

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		std::cin >> input;
		std::cout << (d[input][1] + d[input][2] + d[input][3]) % MOD << "\n";
	}
}