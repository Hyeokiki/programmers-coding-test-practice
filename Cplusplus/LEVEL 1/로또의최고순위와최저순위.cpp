//22.01.04 로또의 최고 순위와 최저 순위 by CJHofficial

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int bestRank = 7;
    int worstRank = 7;

    for (int i : win_nums) {
        for (int j : lottos) {
            if (i == j) worstRank -= 1;
        }
    }
    bestRank = worstRank;
    for (int j : lottos) {
        if (j == 0) bestRank -= 1;
    }

    if (bestRank > 5) bestRank = 6;
    if (worstRank > 5) worstRank = 6;
    answer.push_back(bestRank);
    answer.push_back(worstRank);

    return answer;
}