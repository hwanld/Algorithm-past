#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int e;
	int s;
	int m;

	std::cin >> e >> s >> m;

	int answer = 1;
	
	while (e != 1 || s != 1 || m != 1) {
		e--; s--; m--;
		if (e <= 0) e = 15;
		if (s <= 0) s = 28;
		if (m <= 0) m = 19;
		answer++;
	}

	std::cout << answer;
}