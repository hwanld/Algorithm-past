#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	int count = 0;

	int container[10] = {};
	for (int i = 0; i < 10; i++) {
		int temp = n % 10;
		n = n / 10;
		container[temp]++; 
		if (n == 0) break;
	}
	int temp = container[6] + container[9];
	temp = temp / 2 + temp % 2;
	container[6] = temp;
	container[9] = temp;
	for (int i = 0; i < 10; i++) 
		if (container[i] > count) count = container[i];
	std::cout << count;
}