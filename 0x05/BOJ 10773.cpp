#include <iostream>
#include <stack>

int main() {
	std::stack<int> st;
	int k;
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		int input;
		std::cin >> input;
		if (input == 0) st.pop();
		else st.push(input);
	}
	long long sum = 0;
	int s = st.size();
	for (int i = 0; i < s; i++) {
		sum += st.top();
		st.pop();
	}
	std::cout << sum;
}