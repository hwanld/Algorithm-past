#include <iostream>
#include <vector>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector <int> v;

	int maxInputValue;
	for (int i = 0; i < n; i++) {
		int input;
		std::cin >> input;
		v.push_back(input);
		if (i == 0) maxInputValue = input;
		else 
			if (maxInputValue < input) maxInputValue = input;
	}

	int* arr = new int[maxInputValue+1];
	for (int i = 0; i < maxInputValue + 1; i++) arr[i] = 1;
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= sqrt(maxInputValue); i++) {
		for (int j = 2; j <= maxInputValue / i; j++) {
			if (arr[i * j] == 0) continue;
			else arr[i * j] = 0;
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		int answer = 0;
		for (int j = 2; j <= v[i] / 2; j++) {
			if (arr[j] == 1) {
				if (arr[v[i] - j] == 1) answer++;
			}
		}
		std::cout << answer << "\n";
	}
}