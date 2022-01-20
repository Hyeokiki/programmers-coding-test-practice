//22.01.14 [1차] 다트 게임 by CJHofficial
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    string NUM = "";
    for (auto s : dartResult) {
        if ((s >= '0') && (s <= '9')) {
            NUM += s;
        }
        else if (s == 'S') {
            score.push_back(stoi(NUM));
            NUM = "";
        }
        else if (s == 'D') {
            score.push_back(pow(stoi(NUM), 2));
            NUM = "";
        }
        else if (s == 'T') {
            score.push_back(pow(stoi(NUM), 3));
            NUM = "";
        }
        else if (s == '*') {
            score[score.size() - 1] = 2 * score[score.size() - 1];
            if (score.size() > 1) score[score.size() - 2] = 2 * score[score.size() - 2];
        }
        else if (s == '#') {
            score[score.size() - 1] = (-1) * score[score.size() - 1];
        }
    }
    for (int s : score) answer += s;
    return answer;
}