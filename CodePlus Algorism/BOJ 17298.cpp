#include <iostream>
#include <vector>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int num;
	std::cin >> num;

	std::vector <int> input_vector;

	for (int i = 0; i < num; i++) {
		int index;
		std::cin >> index;
		input_vector.push_back(index);
	}

	std::vector <int> answer_vector;
	for (int i = 0; i < num; i++)
		answer_vector.push_back(-1);

	std::stack <int> index_stack;
	for (int i = 0; i < num; i++) {
		if (index_stack.empty() || input_vector[index_stack.top()] >= input_vector[i]) {
			index_stack.push(i);
		}
		else {
			while (!index_stack.empty()) {
				if (input_vector[index_stack.top()] < input_vector[i]) {
					answer_vector[index_stack.top()] = input_vector[i];
					index_stack.pop();
				}
				else break;
			}
			index_stack.push(i);
		}
	}

	for (int i = 0; i < num; i++)
		std::cout << answer_vector[i] << " ";
}