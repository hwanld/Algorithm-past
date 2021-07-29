#include <iostream>
#include <string>
#include <vector>

typedef struct stick {
	int open;
	int close;
}stick;

int main() {
	std::string inputstr;
	std::cin.clear();
	std::getline(std::cin,inputstr);

	std::vector <stick> stick_vector;
	std::vector <int> lazer_vector;

	int stick_vector_index = 0;
	
	for (int i = 0; i < inputstr.size(); i++) {
		char ch = inputstr[i];
		if (ch == '(') {
			if (inputstr[i + 1] == ')')
				lazer_vector.push_back(i);
			else {
				stick newstick;
				newstick.open = i;
				stick_vector.push_back(newstick);
			}
		}
		else if (ch == ')') {
			if (inputstr[i - 1] == '(') continue;
			else {
				stick_vector[stick_vector_index].close = i;
				stick_vector_index++;
			}
		}
	}

	int answer = stick_vector.size();

	for (int i = 0; i < stick_vector.size(); i++) {
		for (int j = 0; j < lazer_vector.size(); j++) {
			if (stick_vector[i].open<lazer_vector[j] && stick_vector[i].close>lazer_vector[j])
				answer++;
		}
	}

	std::cout << answer;
}