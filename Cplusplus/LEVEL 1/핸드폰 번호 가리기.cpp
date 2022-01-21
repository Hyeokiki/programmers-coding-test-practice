//22.01.21 핸드폰 번호 가리기 by CJHofficial

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int s = phone_number.size();
    for (int i = 0; i < s - 4; i++) answer += "*";
    for (int j = s - 4; j < s; j++) answer += phone_number[j];
    return answer;
}