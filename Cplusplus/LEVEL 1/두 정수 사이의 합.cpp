//22.01.17 두 정수 사이의 합 by CJHofficial
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int temp = b;
    if (a > b) {
        b = a;
        a = temp;
    }
    else if (a == b) {
        return a;
    }
    for (int i = a; i <= b; i++) {
        answer += i;
    }
    return answer;
}