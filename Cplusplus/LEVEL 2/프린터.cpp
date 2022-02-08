//22.02.04 프린터 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

bool mySort(pair<int, int>p1, pair<int, int>p2) {
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int>> pairList; //pair<중요도, 원래 index>
    stack<int> st4max; //최대값 확인용
    queue<pair<int, int>> Q;
    for (int i = 0; i < priorities.size(); i++) {
        pairList.push_back(pair<int, int>(priorities[i], i));
        Q.push(pair<int, int>(priorities[i], i));
    }
    sort(pairList.begin(), pairList.end(), mySort);
    for (auto p : pairList) {
        st4max.push(p.first);
    }
    int COUNT = 1;
    while (true) {
        int max = st4max.top();
        auto Qpair = Q.front();
        if (max == Qpair.first) {
            if (Qpair.second == location) {
                answer = COUNT;
                break;
            }
            st4max.pop();
            Q.pop();
            COUNT += 1;
        }
        else {
            Q.pop();
            Q.push(Qpair);
        }
    }
    return answer;
}