#include <iostream>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<std::string> v;

	std::cin.ignore();
	for (int i = 0; i < n; i++) {
		std::string inputstr;
		std::getline(std::cin, inputstr);
		v.push_back(inputstr);
	}

	for (int i = 0; i < n; i++) {
		char ch;
		int index = 0;
		for (int j = 0; j < v[i].size(); j++) {
			ch = v[i][j];
			if (ch == '(') index++;
			else if (ch == ')') index--;
			if (index < 0) break;
		}
		if (index == 0) std::cout << "YES" << std::endl;
		else std::cout << "NO" << std::endl;
	}
}