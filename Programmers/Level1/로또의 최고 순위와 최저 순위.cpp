#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max = 0;
    int min = 0;
    int zero_count = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) zero_count++;
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) min++;
        }
    }
    max += zero_count;
    max += min;
    if (max < 2) max = 1;
    if (min < 2) min = 1;

    max = 7 - max;
    min = 7 - min;

    answer.push_back(max);
    answer.push_back(min);
    return answer;

}