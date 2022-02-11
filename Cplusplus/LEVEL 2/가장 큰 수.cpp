//22.02.08 가장 큰 수 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool mySort(string s1, string s2) {
    return (s1 + s2) > (s2 + s1);
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numList;
    for (auto num : numbers) numList.push_back(to_string(num));
    sort(numList.begin(), numList.end(), mySort);
    for (auto s : numList) answer += s;
    if (answer[0] == '0') return "0";
    return answer;
}