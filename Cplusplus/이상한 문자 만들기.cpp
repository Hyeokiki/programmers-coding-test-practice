//22.01.19 이상한 문자 만들기 by CJHofficial

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int mark = -1;
    for (auto c : s) {
        if (c == ' ') {
            mark = -1;
            answer += " ";
            continue;
        }
        mark += 1;
        answer += ((mark % 2) == 0) ? toupper(c) : tolower(c);
    }
    return answer;
}