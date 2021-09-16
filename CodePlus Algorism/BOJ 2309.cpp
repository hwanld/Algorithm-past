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

	//9명중 7명 선택임으로 선택되지 않는 2명의 index를 i,j에다가 저장
	//2중 반복문을 break하기 위해서 flag라는 bool 변수를 사용
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

	//<중요> algorithm 헤더의 sort 알고리즘을 사용하면 쉽게 정렬이 가능하다.
	std::sort(answer, answer+7);

	for (int i = 0; i < 7; i++) {
		std::cout << answer[i] << "\n";
	}
}