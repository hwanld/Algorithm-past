#include <iostream>
#include <vector>

bool find_prime(int n);

int main() {
	int n;
	std::cin >> n;
	std::vector <int> inputVector;
	for (int i = 0; i < n; i++) {
		int item;
		std::cin >> item;
		inputVector.push_back(item);
	}
	int answer = 0;
	for (int i = 0; i < n; i++) 
		if (find_prime(inputVector[i])) answer++;
	std::cout << answer;
}

bool find_prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i < n; i++) 
		if (n % i == 0) return false;
	return true;
}
