#include <iostream>
#include <vector>


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int input;
	std::cin >> input;

	int answer = 0;

	answer += input / 5;
	answer += input / 25;
	answer += input / 125;

	std::cout << answer;
}