#include <iostream>

int sum = 0;
void hanoi(int a, int b, int c, int n);
void getHowmuch(int a, int b, int c, int n);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	getHowmuch(1, 2, 3, n);
	std::cout << sum << "\n";
	hanoi(1, 2, 3, n);
}

//n개의 하노이 탑을 a에서 c로 옮기는 함수
void hanoi(int a, int b, int c, int n) {
	if (n == 1) {
		std::cout << a << " " << c << "\n";
	}
	else {
		hanoi(a, c, b, n - 1);
		hanoi(a, b, c, 1);
		hanoi(b, a, c, n - 1);
	}
}

void getHowmuch(int a, int b, int c, int n) {
	if (n == 1) sum++;
	else {
		getHowmuch(a, c, b, n - 1);
		getHowmuch(a, b, c, 1);
		getHowmuch(b, a, c, n - 1);
	}
}
