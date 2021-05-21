#include <iostream>
#include <list>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);

	std::list<char> L;

	std::string str;
	std::cin >> str;

	int num;
	std::cin >> num;

	for (int i = 0; i < str.length(); i++) 
		L.push_back(str[i]);

	std::list<char>::iterator it = L.end();

	for (int i = 0; i < num; i++) {
		char command;
		std::cin >> command;

		switch (command) {
		case 'L' :
			if (it == L.begin()) break;
			it--; break;
		case 'D' :
			if (it == L.end()) break;
			it++; break;
		case 'B' :
			if (it == L.begin()) break;
			it = L.erase(--it); break;
		case 'P' : 
			char input;
			std::cin >> input;
			L.insert(it, input); break;
		}
	}
	
	//iterator를 사용해서 출력하는 방법
	for (it = L.begin(); it != L.end(); it++)
		std::cout << *it;
}