#include <iostream>
#include <vector>

long long getDP(std::vector <int> upperSticker, std::vector <int> lowerSticker);
int max_2(int a, int b);
int max_3(int a, int b, int c);
int arrDP[100000][3];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int stickerNumber;
	std::cin >> stickerNumber;
	std::vector <int> answer;
	for (int i = 0; i < stickerNumber; i++) {
		int rowNumber;
		std::cin >> rowNumber;

		std::vector <int> upperSticker;
		std::vector <int> lowerSticker;
		upperSticker.clear();
		lowerSticker.clear();

		for (int i = 0; i < rowNumber; i++) {
			int input;
			std::cin >> input;
			upperSticker.push_back(input);
		}

		for (int i = 0; i < rowNumber; i++) {
			int input;
			std::cin >> input;
			lowerSticker.push_back(input);
		}

		answer.push_back(getDP(upperSticker, lowerSticker));
	}

	for (int i = 0; i < answer.size(); i++) std::cout << answer[i]<<"\n";
}

long long getDP(std::vector <int> upperSticker, std::vector <int> lowerSticker){

	long long answer = 0;
	int rowNumber = upperSticker.size();

	//0-> upper sticker is selected
	//1-> lower sticker is selected
	//2-> row n's sticker is not selected
	
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 3; j++) arrDP[i][j] = 0;
	}

	arrDP[0][0] = upperSticker[0];
	arrDP[0][1] = lowerSticker[0];
	arrDP[0][2] = 0;


	for (int i = 1; i < rowNumber; i++) {
		arrDP[i][0] = max_2(arrDP[i - 1][1], arrDP[i - 1][2]) + upperSticker[i];
		arrDP[i][1] += max_2(arrDP[i - 1][0], arrDP[i - 1][2]) + lowerSticker[i];
		arrDP[i][2] += max_2(arrDP[i - 1][0], arrDP[i - 1][1]);
	}
	answer = max_3(arrDP[rowNumber - 1][0], arrDP[rowNumber - 1][1], arrDP[rowNumber - 1][2]);
	return answer;
}

int max_2(int a, int b) {
	if (a > b) return a;
	else return b;
}

int max_3(int a, int b, int c) {
	if (a >= b && a >= c) return a;
	else if (b >= a && b >= c) return b;
	else return c;
}