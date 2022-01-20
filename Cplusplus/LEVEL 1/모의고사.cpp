//22.01.07 모의고사 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first = { 1, 2, 3, 4, 5 };
    vector<int> second = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> third = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> students = { 0, 0, 0 };

    for (int i = 0; i < answers.size(); i++) {
        int a = answers[i];
        if (a == first[i % first.size()]) students[0] += 1;
        if (a == second[i % second.size()]) students[1] += 1;
        if (a == third[i % third.size()]) students[2] += 1;
    }
    int MAX = *max_element(students.begin(), students.end());

    for (int i = 0; i < 3; i++) {
        if (students[i] == MAX) answer.push_back(i + 1);
    }
    return answer;
}