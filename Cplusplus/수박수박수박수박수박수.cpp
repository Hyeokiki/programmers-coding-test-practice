//22.01.18 수박수박수박수박수박수? by CJHofficial

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string SUBAK[2] = { "수","박" };
    for (int i = 0; i < n; i++) answer += SUBAK[i % 2];

    return answer;
}