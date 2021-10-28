#include <iostream>
#include <algorithm>

int picture[501][501];
bool visit[501][501];

void start(int m, int n);
bool valid(int m, int n);

int count;
int surface;
int temp_surface;
int x, y;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> x >> y;

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			int input;
			std::cin >> input;
			picture[i][j] = input;
		}
	}

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (valid(i, j)) {
				start(i, j);
				count++;
				surface = std::max(surface, temp_surface);
				temp_surface = 0;
			}
		}
	}
	std::cout << count << "\n" << surface;
}

void start(int m, int n) {
	visit[m][n] = true;
	temp_surface++;
	if (valid(m - 1, n)) start(m - 1, n);
	if (valid(m + 1, n)) start(m + 1, n);
	if (valid(m, n - 1)) start(m, n - 1);
	if (valid(m, n + 1)) start(m, n + 1);
}

bool valid(int m, int n) {
	if (m <= 0 || n <= 0) return false; //유효하지 않은 경우->탐색불가
	if (m > x || n > y) return false; //유효하지 않은 경우->탐색 불가
	if (!picture[m][n]) return false; //값이 0인 경우->탐색불가
	if (visit[m][n]) return false; //이미 탐색한 지역인 경우->탐색할 필요 X
	return true;
}