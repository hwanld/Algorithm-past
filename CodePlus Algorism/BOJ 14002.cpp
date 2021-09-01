#include <iostream>
#include <stack>
#include <vector>


int arr[1001];
int dp[1001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int input;
		std::cin >> input;
		arr[i] = input;
	}

	dp[1] = 1;
	int max_dp = 1;
	int max_dp_index = 1; //dp값이 가장 큰 숫자의 index
	for (int i = 2; i <= n; i++) {
		int dp_value = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j] > dp_value) {
					dp_value = dp[j];
				}
			}
		}
		dp[i] = dp_value + 1;
		if (dp[i] > max_dp) {
			max_dp = dp[i];
			max_dp_index = i;
		}
	}
	

	std::stack <int> s;
	int push_dp_index = dp[max_dp_index];
	for (int i = max_dp_index; i > 0; i--) {
		if (push_dp_index == dp[i]) {
			s.push(arr[i]);
			push_dp_index--;
		}
	}

	int s_size = s.size();
	std::cout << s_size << "\n";
	for (int i = 0; i < s_size; i++) {
		std::cout << s.top() << " ";
		s.pop();
	}
}