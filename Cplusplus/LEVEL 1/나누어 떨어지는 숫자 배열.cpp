//22.01.17 나누어 떨어지는 숫자 배열 by CJHofficial
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int num : arr) {
        if ((num % divisor) == 0) {
            answer.push_back(num);
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.size() == 0) answer.push_back(-1);
    return answer;
}
