#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int distance(int cur, int des);
std::string solution(std::vector <int> numbers, std::string hand);

std::vector <int> visit;

int main() {
	std::vector <int> numbers = { 1,3,4,5,8,2,1,4,5,9,5 };
	std::cout << solution(numbers, "right");
}

std::string solution(std::vector<int> numbers, std::string hand) {
	std::string answer = "";
	int left = 10;
	int right = 12;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0) numbers[i] = 11;

		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer.push_back('L');
			left = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer.push_back('R');
			right = numbers[i];
		}
		else {
			if (distance(right, numbers[i]) < distance(left, numbers[i])) {
				answer.push_back('R');
				right = numbers[i];
			}
			else if (distance(right, numbers[i]) > distance(left, numbers[i])) {
				answer.push_back('L');
				left = numbers[i];
			}
			else {
				if (hand == "left") {
					answer.push_back('L');
					left = numbers[i];
				}
				else {
					answer.push_back('R');
					right = numbers[i];
				}
			}
		}
	}
	return answer;
}

int distance(int cur, int des) {
	if (cur == 1 || cur == 4 || cur == 7 || cur == 10) {
		if (cur + 1 == des) return 1;
		else {
			if (cur > des) return 1 + distance(cur - 3, des);
			else return 1 + distance(cur + 3, des);
		}
	}
	else if (cur == 3 || cur == 6 || cur == 9 || cur == 12) {
		if (cur - 1 == des) return 1;
		else {
			if (cur > des) return 1 + distance(cur - 3, des);
			else return 1 + distance(cur + 3, des);
		}
	}
	else {
		if (cur == des) return 0;
		else if (cur > des) return 1 + distance(cur - 3, des);
		else return 1 + distance(cur + 3, des);
	}
}