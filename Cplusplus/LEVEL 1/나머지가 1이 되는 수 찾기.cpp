//22.01.13 나머지가 1이 되는 수 찾기 by CJHofficial
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    while ((n % answer) != 1) answer++;
    return answer;
}