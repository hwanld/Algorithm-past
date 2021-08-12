#include <iostream>

int cal_5(int n);
int cal_2(int n);
long sqrt_5(int n);
long sqrt_2(int n);
int min(int a, int b);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	
	int num_5 = cal_5(n) - cal_5(m) - cal_5(n - m);
	int num_2 = cal_2(n) - cal_2(m) - cal_2(n - m);
	std::cout << min(num_5,num_2);

}

int cal_5(int n) {
	int i = 1;
	int answer = 0;
	while (1) {
		answer += n / sqrt_5(i);
		i++;
		if (n / sqrt_5(i) == 0) break;
	}
	return answer;
}
int cal_2(int n) {
	int i = 1;
	int answer = 0;
	while (1) {
		answer += n / sqrt_2(i);
		i++;
		if (n / sqrt_2(i) == 0) break;
	}
	return answer;
}
long sqrt_5(int n) {
	if (n == 1) return 5;
	else return 5 * sqrt_5(n - 1);
}
long sqrt_2(int n) {
	if (n == 1) return 2;
	else return 2 * sqrt_2(n - 1);
}

int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}