#include <iostream>
#include <string>
#include <vector>

int solution(std::vector <int> absolutes, std::vector <bool> signs) {
	int sum = 0;
	std::vector <int> answer;
	for (int i = 0; i < absolutes.size(); i++) {
		int temp;
		temp = absolutes[i];
		if (!signs[i]) temp *= -1;
		answer.push_back(temp);
	}
	for (int i = 0; i < answer.size(); i++) sum += answer[i];
	return sum;
}