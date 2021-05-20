#include <iostream>
#include <string>

int check_possible(std::string& s1, std::string& s2);
int main() {
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::string s1, s2;
		std::cin >> s1 >> s2;
		arr[i] = check_possible(s1, s2);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) std::cout << "Possible\n";
		else std::cout << "Impossible\n";
	}
}

int check_possible(std::string& s1, std::string& s2) {
	if (s1.length() != s2.length()) return 0;
	int alphamap_s1[26] = {};
	int alphamap_s2[26] = {};
	for (int i = 0; i < s1.length(); i++) {
		int temp = s1[i] - 'a';
		alphamap_s1[temp]++;
	}
	for (int i = 0; i < s2.length(); i++) {
		int temp = s2[i] - 'a';
		alphamap_s2[temp]++;
	}
	for (int i = 0; i < 26; i++) 
		if (alphamap_s1[i]!=alphamap_s2[i]) return 0;
	return 1;
}
