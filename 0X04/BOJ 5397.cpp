#include <iostream>
#include <list>
#include <string>

void get_password(std::string& str);
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int num;
	std::cin >> num;

	std::string* str = new std::string[num];

	for (int i = 0; i < num; i++)
		std::cin >> str[i];

	for (int i = 0; i < num; i++)
		get_password(str[i]);
}

void get_password(std::string& str) {
	std::list<char> l;
	std::list<char>::iterator it = l.begin();

	for (char c : str) {
		switch (c) {
		case '<' :
			if (it == l.begin()) break;
			it--; break;
		case '>' :
			if (it == l.end()) break;
			it++; break;
		case '-' :
			if (it == l.begin()) break;
			it = l.erase(--it); 
			break;
		default :
			l.insert(it, c);
			break;
		}
	}

	for (it = l.begin(); it != l.end(); it++)
		std::cout << *it;
	std::cout << "\n";
}