#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int numOfCase;
	std::cin >> numOfCase;
	
	std::vector <std::string> OutVector;
	std::cin.ignore();
	for (int i = 0; i < numOfCase; i++) {
		std::string inputString;
		std::getline(std::cin, inputString);
		OutVector.push_back(inputString);
	}

	for (int i = 0; i < numOfCase; i++) {
		std::stack<char> st;
		for (int j = 0; j < OutVector[i].size()+1; j++) {
			char ch = OutVector[i][j];
			if (ch == ' '|| j == OutVector[i].size()) {
				for (char c = st.top(); st.size() != 0;st.pop()) 
					std::cout << st.top();
				std::cout << " ";
			}
			else st.push(ch);
		}
		std::cout << std::endl;
	}
}