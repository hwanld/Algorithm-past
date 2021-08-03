#include <iostream>
#include <stack>
#include <string>
#include <vector>

//ASCII code A : 65, Z : 90
//(int)A-65 = 0, (int)Z-65= 25

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::string order;
	std::vector <int> num_vector;

	std::cin >> n;
	std::cin >> order;

	for (int i = 0; i < n; i++) {
		double k;
		std::cin >> k;
		num_vector.push_back(k);
	}

	std::stack <double> st;

	for (int i = 0; i < order.size(); i++) {
		char ch = order[i];
		if (ch == '*') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			double c = a * b;
			st.push(c);
		}
		else if (ch == '/') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			double c = b / a;
			st.push(c);
		}
		else if (ch == '+') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			double c = a + b;
			st.push(c);
		}
		else if (ch == '-') {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			double c = b - a;
			st.push(c);
		}
		else 
			st.push(num_vector[(int)ch - 65]);
	}
	double answer = st.top();
	printf("%.2f", answer);
}