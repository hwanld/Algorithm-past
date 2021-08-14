#include <iostream>
#include <vector>
int GCD(int a, int b);
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int index;
		std::cin >> index;
		std::vector <int> v;
		long long sum = 0;

		for (int j = 0; j < index; j++) {
			int input;
			std::cin >> input;
			v.push_back(input);
		}


		for (int a = 0; a < index - 1; a++) {
			for (int b = a + 1; b < index; b++) {
				sum += GCD(v[a], v[b]);
			}
		}

		std::cout << sum;
		std::cout << "\n";
	}
	return 0;
}

int GCD(int a, int b) {
	if (b >= a) {
		int r;
		r = a;
		a = b;
		b = r;
	}
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}