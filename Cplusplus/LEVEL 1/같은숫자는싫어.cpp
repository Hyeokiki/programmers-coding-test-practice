//22.01.17 같은 숫자는 싫어 by CJHofficial
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int temp = -1;
    vector<int> answer;
    for (int num : arr) {
        if (temp != num) answer.push_back(num);
        temp = num;
    }

    return answer;
}