//22.01.05 없는 숫자 더하기 by CJHofficial
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int sum = 0;
    //0~9까지 더하면 45임 모야이거
    for (int num : numbers) {
        sum += num;
    }
    answer = 45 - sum;

    return answer;
}