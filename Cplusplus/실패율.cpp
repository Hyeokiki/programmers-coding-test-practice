//22.01.11 ½ÇÆÐÀ² by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, double>& l, const pair<int, double>& r) {
    if (l.second == r.second) return l.first < r.first;
    return (l.second > r.second);
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, int>> playerCount;
    for (int i = 0; i < (N + 2); i++) {
        playerCount.push_back(pair<int, int>(0, 0));
    }
    for (int i : stages) {
        for (int j = 1; j <= i; j++) {
            playerCount[j].second += 1;
            if (j == i) playerCount[j].first += 1;
        }
    }
    vector<pair<int, double>> sortVec;
    for (int i = 1; i < playerCount.size() - 1; i++) {
        if (playerCount[i].second == 0) {
            sortVec.push_back(pair<int, double>(i, 0));
        }
        else {
            sortVec.push_back(pair<int, double>(i, (double)playerCount[i].first / playerCount[i].second));
        }
    }
    sort(sortVec.begin(), sortVec.end(), compare);
    for (auto p : sortVec) answer.push_back(p.first);
    return answer;
}