//22.02.02 수식 최대화 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<string> priority;
    priority.push_back("*");
    priority.push_back("+");
    priority.push_back("-");

    sort(priority.begin(), priority.end());
    long long max = 0;
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
        numList.push_back(temp);

        for (int i = 0; i < 3; i++) {
            auto it = find(numList.begin(), numList.end(), priority[i]);
            while (it != numList.end()) {
                string snum1 = *(it - 1);
                string snum2 = *(it + 1);
                long long num1 = stol(snum1);
                long long num2 = stol(snum2);
                long long result;
                if (*it == "+") result = num1 + num2;
                else if (*it == "-") result = num1 - num2;
                else if (*it == "*") result = num1 * num2;
                numList.insert(it - 1, to_string(result));
                numList.erase(it, it + 3);
                it = find(numList.begin(), numList.end(), priority[i]);
            }

        }
        long long target = stol(numList[0]);
        if (abs(target) > max) max = abs(target);
    } while (next_permutation(priority.begin(), priority.end()));
    answer = max;
    return answer;
}