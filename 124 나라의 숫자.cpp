//22.01.26 124 나라의 숫자 by CJHofficial

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string dict = "124";
    string answer = "";
    while (n > 0) {
        answer = dict[(n - 1) % 3] + answer;
        n = (n - 1) / 3;
    }
    return answer;
}