//22.01.17 문자열 내 마음대로 정하기 by CJHofficial
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index;

bool mysort(string s1, string s2) {
    if (s1[index] < s2[index]) return true;
    else if (s1[index] == s2[index]) {
        return s1 < s2;
    }
    else return false;
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    index = n;
    sort(strings.begin(), strings.end(), mysort);
    return strings;
}