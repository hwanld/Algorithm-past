#include <iostream>
#include <algorithm>

char candy[51][51];
int size;
int get_max_candy(char candy[][51]);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> size;
	int max = 0;

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			char input;
			std::cin >> input;
			candy[i][j] = input;
		}
	}

	//가로로 swap하는 경우
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j < size; j++) {
			char copy_candy[51][51];
			std::copy(&candy[0][0], &candy[0][0] + 2601, &copy_candy[0][0]);
			char temp = copy_candy[i][j];
			copy_candy[i][j] = copy_candy[i][j + 1];
			copy_candy[i][j + 1] = temp;

			max = std::max(max, get_max_candy(copy_candy));
		}
	}

	//세로로 swap하는 경우
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j < size; j++) {
			char copy_candy[51][51];
			std::copy(&candy[0][0], &candy[0][0] + 2601, &copy_candy[0][0]);
			char temp = copy_candy[j][i];
			copy_candy[j][i] = copy_candy[j + 1][i];
			copy_candy[j + 1][i] = temp;

			max = std::max(max, get_max_candy(copy_candy));
		}
	}

	std::cout << max;
}

int get_max_candy(char candy[][51]) {
	int max = 0;
	int count = 1;
	char temp;
	//가로로 연속되는 경우를 먼저 check한다
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			//새로운 가로줄이 시작되는 경우, temp에 candy[i][j]의 값을 넣어준다
			if (j == 1) {
				temp = candy[i][j];
				count = 1;
			}
			//새롭게 시작하는 가로줄이 아닌 경우
			else {
				if (temp == candy[i][j]) {
					count++;
					max = std::max(count, max);
				}//만약 현재의 candy값이 temp와 같다면 count++
				else { //현재의 candy값이 새로운 값이라면
					max = std::max(count, max); //max의 값을 최신화해주고
					count = 1; //count를 1로 다시 계산
					temp = candy[i][j]; //temp도 새로운 값으로 바꿔준다
				}
			}
		}
	}
	count = 1; 
	//이후 세로로 연속되는 경우도 check한다
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (j == 1) {
				temp = candy[j][i];
				count = 1;
			}
			else {
				if (temp == candy[j][i]) {
					count++;
					max = std::max(count, max);
				}
				else {
					max = std::max(count, max);
					count = 1;
					temp = candy[j][i];
				}
			}
		}
	}
	return max;
}