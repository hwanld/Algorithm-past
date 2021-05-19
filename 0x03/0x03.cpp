#include <iostream>
#include <vector>
int main() {
	std::vector<int> v1 = { 1,2,3,4,5,6 };
	std::vector<int> v2 = { 6,5,4,3,2,1 };

	for (int e : v1)
		std::cout << e << " ";

	std::cout << "\n";

	for (int i = 0; i < v1.size(); i++)
		std::cout << v1[i] << " ";

	std::cout << "\n";

	for (int e : v2)
		std::cout << e << " ";
}