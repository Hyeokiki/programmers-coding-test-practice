//22.01.26 기능개발 by CJHofficial
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> needDayVec;
    int remainWork, needDay;
    int finishedWork = 1;
    map<int, int> result;
    for (int i = 0; i < progresses.size(); i++) {
        remainWork = 100 - progresses[i];
        needDay = ceil((double)remainWork / speeds[i]);
        needDayVec.push_back(needDay);
    }
    int ndvSize = needDayVec.size();
    for (int i = (ndvSize - 1); i >= 0; i--) {
        int MAX = needDayVec[i];
        for (int j = i - 1; j >= 0; j--) {
            if (MAX < needDayVec[j]) MAX = needDayVec[j];
        }
        result[MAX]++;
    }
    for (auto p : result) {
        answer.push_back(p.second);
    }
    return answer;
}