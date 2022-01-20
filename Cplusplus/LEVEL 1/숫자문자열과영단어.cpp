//22.01.04 숫자 문자열과 영단어 by CJHofficial

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    string Numlist[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

    for (int i = 0; i < 10; i++) {
        string Target = Numlist[i];
        while (s.find(Target) != string::npos) {
            int pos = s.find(Target);
            s.replace(pos, Target.size(), to_string(i));
        }
    }
    answer = stoi(s);

    return answer;
}
