#include <iostream>
#include <vector>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::vector <int> inputVector;

	while (1) {
		int input;
		std::cin >> input;
		if (input == 0) break;
		else inputVector.push_back(input);
	}
	int max_input = inputVector[0];
	for (int i = 0; i < inputVector.size(); i++) 
		if (inputVector[i] > max_input) max_input = inputVector[i];

	int* prime = new int[max_input+1];
	for (int i = 0; i < max_input; i++)
		prime[i] = 1;

	for (int i = 2; i <=sqrt(max_input); i++) {
		if (prime[i] == 0) continue;
		for (int j = i * i; j <= max_input; j += i)
			prime[j] = 0;
	}

	for (int i = 0; i < inputVector.size(); i++) {
		int sum = inputVector[i];
		int is_able = 0;
		for (int j = 3; j <= sum / 2; j+=2) {
			if (prime[j] == 1) {
				if (prime[sum - j] == 1) {
					std::cout << sum << " = " << j << " + " << sum - j << "\n";
					is_able = 1;
					break;
				}
			}
		}
		if (is_able == 0) std::cout << "Goldbach's conjecture is wrong.";
	}

	delete[] prime;
}