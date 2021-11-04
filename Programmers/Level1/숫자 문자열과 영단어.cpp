#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stack>

int convert(std::string s);
int solution(std::string s);

int solution(std::string s) {
	std::stack <int> answer_stack;
	for (int i = 0; i < s.length();) {
		if (isdigit(s[i])) {
			answer_stack.push(s[i]-'0');
			i++;
		}
		else {
			std::string temp;
			while (1) {
				temp.push_back(s[i]);
				if (i == s.length()) break;
				else if (convert(temp) != -1) break;
				i++;
			}
			answer_stack.push(convert(temp));
			i++;
		}
	}
	int answer = 0;
	int digit = 1;
	int temp_size = answer_stack.size();
	
	for (int i = 0; i < temp_size; i++) {
		answer += digit * answer_stack.top();
		answer_stack.pop();
		digit *= 10;
	}
	return answer;
}

int convert(std::string s) {
	if (s == "zero") return 0;
	else if (s == "one") return 1;
	else if (s == "two") return 2;
	else if (s == "three") return 3;
	else if (s == "four") return 4;
	else if (s == "five") return 5;
	else if (s == "six") return 6;
	else if (s == "seven") return 7;
	else if (s == "eight") return 8;
	else if (s == "nine") return 9;
	return -1;
}