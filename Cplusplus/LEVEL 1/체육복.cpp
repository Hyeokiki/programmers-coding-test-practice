//22.01.10 Ã¼À°º¹ by CJHofficial

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student;
    student.assign(n + 2, 1);
    for (int i : reserve) student[i] += 1;
    for (int i : lost) student[i] -= 1;
    for (int j = 1; j <= n; j++) {
        if ((student[j] == 2) || (student[j] == 1)) {
            answer += 1;
        }
        else if (student[j] == 0) {
            if (student[j - 1] == 2) {
                answer += 1;
                student[j - 1] -= 1;
            }
            else if (student[j + 1] == 2) {
                answer += 1;
                student[j + 1] -= 1;
            }
        }
    }

    return answer;
}