//22.01.24 문자열 압축 by CJHofficial

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int maxSize = s.size() / 2;
    for (int i = 1; i <= maxSize; i++) {
        string target = "";
        string pre = "";
        string now = "";
        int count = 1;
        for (int j = 0; j < s.size(); j += i) {
            now = s.substr(j, i);
            if (pre == now) {
                count += 1;
            }
            else {
                if (count > 1) {
                    target += to_string(count) + pre;
                    count = 1;
                }
                else {
                    target += pre;
                }
                pre = now;
            }
            if (j + i >= s.size()) {
                if (count > 1) target += to_string(count);
                target += s.substr(j);
                break;
            }
        }
        if (target.size() < answer) answer = target.size();
    }
    return answer;
}