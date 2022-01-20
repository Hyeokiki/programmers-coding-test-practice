//22.01.07 완주하지 못한 선수 by CJHofficial

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> dictionary;
    for (auto p : participant) dictionary[p]++;
    for (auto c : completion) dictionary[c]--;
    for (auto kv : dictionary) {
        if (kv.second > 0) {
            answer = kv.first;
            break;
        }
    }
    return answer;
}