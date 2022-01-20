//22.01.12 2016³â by CJHofficial

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> day = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    vector<int> MonthDay = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int diff = 0;
    for (int i = 0; i < (a - 1); i++) {
        diff += MonthDay[i];
    }
    diff += b;
    answer += day[(diff - 1) % 7];
    return answer;
}