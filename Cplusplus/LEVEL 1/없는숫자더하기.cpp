//22.01.05 ���� ���� ���ϱ� by CJHofficial
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int sum = 0;
    //0~9���� ���ϸ� 45�� ����̰�
    for (int num : numbers) {
        sum += num;
    }
    answer = 45 - sum;

    return answer;
}