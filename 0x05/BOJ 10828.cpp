#include <iostream>

class stack_type {
	int stack[100001] = {};
	int pos = 0;
public :
	void push(int x);
	int pop();
	int size();
	int empty();
	int top();
};

void stack_type::push(int x) {
	stack[pos++] = x;
}

int stack_type::pop() {
	if (pos == 0) return -1;
	return stack[--pos];
}

int stack_type::size() {
	return pos;
}

int stack_type::empty() {
	if (pos == 0) return 1;
	else return 0;
}

int stack_type::top() {
	if (pos == 0) return -1;
	else return stack[pos-1];
}

int main() {
	stack_type stack;
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		if (str == "push") {
			int num;
			std::cin >> num;
			stack.push(num); 
		}
		else if (str == "pop") std::cout << stack.pop()<<"\n";
		else if (str == "size") std::cout << stack.size() << "\n";
		else if (str == "empty") std::cout << stack.empty() << "\n";
		else if (str == "top") std::cout << stack.top() << "\n";
	}
	return 0;
}