//22.01.20 ���� ������ �Ǻ� by CJHofficial

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    double s = sqrt(n);
    if (s == (int)s) {
        answer = pow(s + 1, 2);
    }
    return answer;
}