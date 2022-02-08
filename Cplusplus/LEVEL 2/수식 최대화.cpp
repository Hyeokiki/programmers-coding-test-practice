//22.02.02 수식 최대화 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    char priority[3] = { '*','+','-' };
    sort(priority.begin(), priority.end());
    int max = 0;
    do {
        string temp = "";
        vector<string> numList;
        for (int i = 0; i < expression.size(); i++) {
            if (isdigit(expression[i])) {
                temp += expression[i];
            }
            else {
                numList.push_back(temp);
                temp = "";
                temp += expression[i];
                numList.push_back(temp);
                temp = "";
            }

        }
        expression.find(priority[0]);

    } while (next_permutation(priority.begin(), priority.end()));
    return answer;
}