#include <iostream>
#include <vector>

int gcd(int a, int b);
int sub(int a, int b);
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, s;
	std::cin >> n >> s;
	std::vector <int> v;

	if (n == 1) {
		int input;
		std::cin >> input;
		std::cout << sub(s,input);
	}

	else {
		for (int i = 0; i < n; i++) {
			int input;
			std::cin >> input;
			v.push_back(input);
		}
		int answer = gcd(sub(s, v[0]), sub(s, v[1]));
		if (n == 2)
			std::cout << answer;
		else {
			for (int j = 2; j < n ; j++) 
				answer = gcd(answer, sub(s, v[j]));
			std::cout << answer;
		}
	}
}

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int sub(int a, int b) {
	if (a >= b) return a - b;
	else return b - a;
}