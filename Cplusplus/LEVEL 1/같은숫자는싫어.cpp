//22.01.17 ���� ���ڴ� �Ⱦ� by CJHofficial
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