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

	//���η� swap�ϴ� ���
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

	//���η� swap�ϴ� ���
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
	//���η� ���ӵǴ� ��츦 ���� check�Ѵ�
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			//���ο� �������� ���۵Ǵ� ���, temp�� candy[i][j]�� ���� �־��ش�
			if (j == 1) {
				temp = candy[i][j];
				count = 1;
			}
			//���Ӱ� �����ϴ� �������� �ƴ� ���
			else {
				if (temp == candy[i][j]) {
					count++;
					max = std::max(count, max);
				}//���� ������ candy���� temp�� ���ٸ� count++
				else { //������ candy���� ���ο� ���̶��
					max = std::max(count, max); //max�� ���� �ֽ�ȭ���ְ�
					count = 1; //count�� 1�� �ٽ� ���
					temp = candy[i][j]; //temp�� ���ο� ������ �ٲ��ش�
				}
			}
		}
	}
	count = 1; 
	//���� ���η� ���ӵǴ� ��쵵 check�Ѵ�
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