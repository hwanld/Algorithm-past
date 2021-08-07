#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string inputstr;
	std::cin >> inputstr;
	std::vector <std::string> strVector;
	int length = inputstr.length();
	for (int i = 0; i < length; i++) 
		strVector.push_back(inputstr.substr(i));
	std::sort(strVector.begin(), strVector.end());
	for (int i = 0; i < length; i++)
		std::cout << strVector[i] << std::endl;
}