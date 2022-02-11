//22.02.03 Æ©ÇÃ by CJHofficial

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

bool mySort(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    int order = -1;
    unordered_map<int, int> MAP;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || i == s.size() - 1) continue;
        if (isdigit(s[i])) {
            temp += s[i];
            if (isdigit(s[i + 1])) continue;
            MAP[stoi(temp)]++;
            temp = "";
        }
    }
    vector<pair<int, int>> pairList(MAP.begin(), MAP.end());
    sort(pairList.begin(), pairList.end(), mySort);
    for (auto p : pairList) {
        answer.push_back(p.first);
    }
    return answer;
}