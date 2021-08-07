#include <iostream>
#include <vector>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector <int> valueVector;
	std::vector <int> digitVector;

	for (int i = 0; i < 4; i++) {
		int n;
		std::cin >> n;
		valueVector.push_back(n);
		digitVector.push_back(0);
	}
	
	for (int i = 0; i < 4; i++) {
		int n = valueVector[i];
		while (1) {
			if (n / 10 > 0) {
				n /= 10;
				digitVector[i]++;
			}
			else break;
		}
	}

	long long int num_AB = valueVector[0] * pow(10, digitVector[1] + 1) + valueVector[1];
	long long int num_CD = valueVector[2] * pow(10, digitVector[3] + 1) + valueVector[3];

	std::cout << num_AB + num_CD;
}