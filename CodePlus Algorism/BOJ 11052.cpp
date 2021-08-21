#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector <int> priceVector;
	//Pn = priceVector[n]
	priceVector.push_back(0);
	for (int i = 1; i <= n; i++) {
		int input;
		std::cin >> input;
		priceVector.push_back(input);
	} 

	int* resultArr = new int[n+1];
	for (int i = 1; i <= n; i++) {
		int maxValue = priceVector[i];
		for (int j = 1; j <= i / 2; j++) {
			if (maxValue < resultArr[j] + resultArr[i - j])
				maxValue = resultArr[j] + resultArr[i - j];
		}
		resultArr[i] = maxValue;
	}
	std::cout << resultArr[n];
}