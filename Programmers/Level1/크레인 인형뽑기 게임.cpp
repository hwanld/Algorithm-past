#include <iostream>
#include <string>
#include <vector>
#include <stack>

int solution(std::vector<std::vector<int>> board, std::vector<int> moves) {
	int answer = 0;
	std::vector <std::stack <int>> boardStack;
	std::stack <int> basket;
	for (int i = 0; i < board.size(); i++) {
		std::stack <int> temp;
		for (int j = 0; j < board.size(); j++) {
			if (board[board.size() - 1 - j][i] == 0) continue;
			else temp.push(board[board.size() - 1 - j][i]);
		}
		boardStack.push_back(temp);
	}
	for (int i = 0; i < moves.size(); i++) {
		int index = moves[i] - 1;
		if (boardStack[index].empty()) continue;
		else {
			int temp = boardStack[index].top();
			boardStack[index].pop();
			if (!basket.empty()) {
				if (basket.top() == temp) {
					answer += 2;
					basket.pop();
				}
				else basket.push(temp);
			}
			else basket.push(temp);	
		}	
	}
	return answer;
}