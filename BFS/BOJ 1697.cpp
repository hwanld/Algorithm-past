#include <iostream>
#include <stack>


std::stack <std::pair<int, int>> st;
std::stack <int> answer_st;
void bfs();
void sub(int number, int count);
void add(int number, int count);
void mul(int number, int count);
bool able(int number, int count);
int n;
int k;

int main() {
	std::cin >> n >> k;
	st.push({ n,0 });
	while (!st.empty())
		bfs();
	printf("BFS is end");
	int answer = answer_st.top();
	answer_st.pop();
	while (!answer_st.empty()) {
		if (answer_st.top() < answer)
			answer = answer_st.top();
		answer_st.pop();
	}
	std::cout << answer;
}

void bfs() {
	int number;
	int count;
	number = st.top().first;
	count = st.top().second;
	printf("%d %d\n", number, count);
	st.pop();
	sub(number, count);
	add(number, count);
	mul(number, count);

}

void sub(int number, int count) {
	number--;
	count++;
	if (able(number, count)) {
		if (number == k)
			answer_st.push(count);
		else
			st.push({ number, count });
	}
}

void add(int number, int count) {
	number++;
	count++;
	if (able(number, count)) {
		if (number == k)
			answer_st.push(count);
		else
			st.push({ number, count });
	}
}

void mul(int number, int count) {
	number*=2;
	count++;
	if (able(number, count)) {
		if (number == k)
			answer_st.push(count);
		else
			st.push({ number, count });
	}
}

bool able(int number, int count) {
	int a = std::max(n - k, k - n);
	if (count >= a) return false;
	if (number < 0) return false;
	if (number > 100000) return false;
	return true;
}
