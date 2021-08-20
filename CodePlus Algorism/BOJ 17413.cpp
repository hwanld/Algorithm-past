#include <iostream>
#include <string>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string inputstr;
	std::stack <char> reverse_stack;
	std::cin.clear();
	std::getline(std::cin, inputstr);

	for (int i = 0; i < inputstr.size(); i++) {
		char ch = inputstr[i];
		if (ch == '<') {
			while (true) {
				std::cout << ch;
				i++;
				ch = inputstr[i];
				if (ch == '>') {
					std::cout << ch;
					break;
				}
			}
		} //특수문자인 경우
		else if (ch == ' ') std::cout << ch;
		else {
			while (true) {
				reverse_stack.push(ch);
				if (inputstr[i + 1] == ' ' || inputstr[i + 1] == '<' || /*inputstr[i] == inputstr.back()*/ i+1==inputstr.length()) break;
				i++;
				ch = inputstr[i];
			}
			while (!reverse_stack.empty()) {
				std::cout << reverse_stack.top();
				reverse_stack.pop();
			}
		}
	}
}

