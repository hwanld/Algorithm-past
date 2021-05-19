#include <iostream>
#include <string>
int main() {
	std::string s1;
	std::cin >> s1;
	int arr[26] = {};
	for (char c : s1)
		arr[c - 'a']++;
	for (int i = 0; i < 26; i++)
		std::cout << arr[i] << " ";
}