//22.01.20 ���� ������������ ��ġ�ϱ� by CJHofficial

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        answer += (s[i] - '0') * pow(10, i);
    }
    return answer;
}