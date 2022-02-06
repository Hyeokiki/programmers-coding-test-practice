#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    for (int cSize : course) {
        unordered_map<string, int> dict;
        for (string s : orders) {
            if (cSize > s.size()) continue;
            vector<bool> check(s.size(), false);
            for (int i = 0; i < cSize; i++) check[i] = true;
            sort(check.begin(), check.end());
            do {
                string target = "";
                for (int j = 0; j < s.size(); j++) {
                    if (check[j]) target += s[j];
                }
                dict[target]++;
            } while (next_permutation(check.begin(), check.end()));
        }
        int max = 0;
        for (auto p : dict) {
            if (p.second >= 2 && p.second > max) max = p.second;
        }
        for (auto p : dict) {
            if (p.second == max) answer.push_back(p.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}