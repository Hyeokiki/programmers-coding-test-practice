//22.01.19 자릿수 더하기 by CJHofficial

#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    while (n > 0) {
        answer += n % 10;
        n = n / 10;
    }
    return answer;
}