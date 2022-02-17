//0210 예상 대진표 by CJHofficial

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while((a/2 == b/2) || (abs(a-b) != 1)){
        a = (a-1)/2 + 1;
        b = (b-1)/2 + 1;
        answer += 1;
    }
    return answer;
}