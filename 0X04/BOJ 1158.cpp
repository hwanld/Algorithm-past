#include <iostream>
#include <list>

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::list<int> l;

	for (int i = 0; i < n; i++)
		l.push_back(i + 1);

	std::list<int>::iterator it = l.begin();

	std::cout << "<";
	for (int i = 0; i < n-1; i++) {
		for (int i = 0; i < k - 1; i++) {
			if (it == l.end())
				it == l.begin();
			it++;
			if (it == l.end())
				it == l.begin();
		}
		std::cout << *it << ", ";
		it = l.erase(it);
		if (it == l.end())
			it == l.begin();
	}
	std::cout << *it << ">";
	return 0;
}

