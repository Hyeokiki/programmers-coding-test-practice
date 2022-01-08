//22.01.07 K¹øÂ° ¼ö by CJHofficial

#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        int count = 0;
        vector<int> sortVec;
        for (int j = (commands[i][0] - 1); j < commands[i][1]; j++) {
            sortVec.push_back(array[j]);
        }
        sort(sortVec.begin(), sortVec.end());
        answer.push_back(sortVec[commands[i][2] - 1]);
    }

    return answer;
}