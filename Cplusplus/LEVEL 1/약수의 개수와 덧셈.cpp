//22.01.11 ����� ������ ���� by CJHofficial
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int temp;
    for (int i = left; i <= right; i++) {
        temp = sqrt(i);
        if (temp * temp == i) answer -= i;
        else answer += i;
    }

    return answer;
}