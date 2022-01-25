//22.01.25 단체 사진 찍기 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int n, vector<string> data) {
    vector<string> kfriend{ "A","C","F","J","M","N","R","T" };
    int answer = 0;
    do {
        string P = "";
        for (string s : kfriend) P += s;
        bool check = true;
        for (string s : data) {
            char condition = s[3];
            int diff = s[4] - '0';
            int index1 = P.find(s[0]);
            int index2 = P.find(s[2]);
            int num = abs(index1 - index2) - 1;
            if (condition == '=') {
                if (diff != num) {
                    check = false;
                    break;
                }
            }
            else if (condition == '<') {
                if (num >= diff) {
                    check = false;
                    break;
                }
            }
            else if (condition == '>') {
                if (num <= diff) {
                    check = false;
                    break;
                }
            }
        }
        if (check) answer += 1;
    } while (next_permutation(kfriend.begin(), kfriend.end()));
    return answer;
}