//22.01.18 문자열 내림차순으로 배치하기 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}