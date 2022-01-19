//22.01.19 시저 암호 by CJHofficial

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (auto c : s) {
        if (c >= 'A' && c <= 'Z') {
            if ((c + n - 'Z') > 0) answer += ('A' - 1 + c + n - 'Z');
            else answer += (c + n);
        }
        else if (c >= 'a' && c <= 'z') {
            if ((c + n - 'z') > 0) answer += ('a' - 1 + c + n - 'z');
            else answer += (c + n);

        }
        else if (c == ' ') answer += ' ';
    }
    return answer;
}