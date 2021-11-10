#include <iostream>
#include <string>
#include <vector>

int count[10];

int solution(std::vector <int> numbers) {
	int answer = 0;
	for (int i = 0; i < numbers.size(); i++) count[numbers[i]]++;
	for (int i = 0; i < 10; i++) if (count[i]==0) answer += i;
	return answer;
}