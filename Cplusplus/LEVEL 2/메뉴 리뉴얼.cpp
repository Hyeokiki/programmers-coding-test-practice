#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> dict;
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    for (int cSize : course) {
        for (string s : orders) {
            if (cSize > s.size()) continue;
            vector<bool> check(s.size(), false);
            for (int i = 0; i < cSize; i++) check[i] = true;
            do {
                string target = "";
                for (int j = 0; j < s.size(); j++) {
                    if (check[j]) target += s[j];
                }
                dict[target]++;
            } while (next_permutation(check.begin(), check.end()));
        }
    }
    for (auto p : dict) {
        if (p.second >= 2) answer.push_back(p.first);
    }
    sort(answer.begin(), answer.end());
    return answer;
}