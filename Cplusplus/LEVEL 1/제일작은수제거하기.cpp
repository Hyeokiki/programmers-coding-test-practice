//22.01.20 제일 작은 수 제거하기 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() <= 1) answer.push_back(-1);
    else {
        arr.erase(min_element(arr.begin(), arr.end()));
        return arr;
    }
    return answer;
}