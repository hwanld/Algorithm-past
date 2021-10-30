#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>

std::string maze[101];
int distance[101][101];
int n, m;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

std::queue <std::pair <int, int>> q;

bool valid(std::pair<int, int> p);
void start();

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::string input;
		std::cin >> input;
		maze[i] = input;
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			distance[i][j] = -1;
		}
	}

	std::pair<int, int> startingPoint = std::make_pair(0, 0);
	distance[0][0] = 0;
	q.push(startingPoint);
	start();
	std::cout << distance[n - 1][m - 1] + 1;
}

bool valid(std::pair<int, int> p) {
	if (p.first < 0 || p.second < 0) return false;
	else if (p.first >= n || p.second >= m) return false;
	else if (distance[p.first][p.second] >= 0) return false;
	else if (maze[p.first][p.second]!='1') return false;
	else return true;
}

void start() {
	while (!q.empty()) {
		std::pair<int, int> currentPoint = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			std::pair<int, int> tempPoint = currentPoint;
			tempPoint.first += dx[i];
			tempPoint.second += dy[i];
			if (valid(tempPoint)) {
				q.push(tempPoint);
				distance[tempPoint.first][tempPoint.second] = distance[currentPoint.first][currentPoint.second] + 1;
			}
		}
	}
}

