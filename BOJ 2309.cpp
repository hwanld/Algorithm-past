#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int heightarr[9];
	int answer[7];
	int heightsumAll = 0;

	for (int i = 0; i < 9; i++) {
		int input;
		std::cin >> input;
		heightarr[i] = input;
		heightsumAll += heightarr[i];
	}

	int exceptIndex_a;
	int exceptIndex_b;

	//9���� 7�� ���������� ���õ��� �ʴ� 2���� index�� i,j���ٰ� ����
	//2�� �ݺ����� break�ϱ� ���ؼ� flag��� bool ������ ���
	bool flag = false;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			int temp = heightsumAll;
			temp -= heightarr[i];
			temp -= heightarr[j];
			if (temp == 100) {
				exceptIndex_a = i;
				exceptIndex_b = j;
				flag = true;
				break;
			}
		}
		if (flag==true) break;
	}

	int tempIndex = 0;
	for (int i = 0; i < 9; i++) {
		if(i!=exceptIndex_a && i!=exceptIndex_b)
			answer[tempIndex++] = heightarr[i];
	}

	//<�߿�> algorithm ����� sort �˰����� ����ϸ� ���� ������ �����ϴ�.
	std::sort(answer, answer+7);

	for (int i = 0; i < 7; i++) {
		std::cout << answer[i] << "\n";
	}
}