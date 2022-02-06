//22.02.01 [1차] 뉴스 클러스터링 by CJHofficial

#include <string>
#include <unordered_map>
#include <cmath>
#include <cctype>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> setA;
    unordered_map<string, int> setB;
    for (int i = 0; i < str1.size(); i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; i < str2.size(); i++) {
        str2[i] = tolower(str2[i]);
    }
    for (int i = 0; i < str1.size() - 1; i++) {
        if (!isalpha(str1[i])) continue;
        if (!isalpha(str1[i + 1])) continue;
        string s = "";
        s += str1[i];
        s += str1[i + 1];
        setA[s]++;
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (!isalpha(str2[i])) continue;
        if (!isalpha(str2[i + 1])) continue;
        string s = "";
        s += str2[i];
        s += str2[i + 1];
        setB[s]++;
    }
    if (setA.empty() && setB.empty()) return 65536;
    double comb = 0;
    double inter = 0;
    for (auto p : setA) {
        auto it = setB.find(p.first);
        if (it != setB.end()) {
            comb += max(setB[p.first], p.second);
        }
        else {
            comb += p.second;
        }
    }
    for (auto p : setB) {
        auto it = setA.find(p.first);
        if (it == setA.end()) {
            comb += p.second;
        }
    }
    for (auto p : setA) {
        auto it = setB.find(p.first);
        if (it != setB.end()) {
            inter += min(p.second, setB[p.first]);
        }
    }
    answer = 65536 * inter / comb;
    return answer;
}