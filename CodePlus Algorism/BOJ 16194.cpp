#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector <int> priceVector;
	int n;
	std::cin >> n;
	priceVector.push_back(0);
	for (int i = 1; i <= n; i++) {
		int input;
		std::cin >> input;
		priceVector.push_back(input);
	}

	int* arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = priceVector[1];
	for (int i = 2; i <= n; i++) {
		int minValue = priceVector[i];
		for (int j = 1; j <= i / 2; j++) {
			if (arr[j] + arr[i - j] < minValue)
				minValue = arr[j] + arr[i - j];
		}
		arr[i] = minValue;
	}

	std::cout << arr[n];
}