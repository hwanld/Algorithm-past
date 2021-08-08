#include <iostream>
#include <cmath>
int gcd(int a, int b);
int lcm(int a, int b);
int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << gcd(a, b) << std::endl << lcm(a, b);
}
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}