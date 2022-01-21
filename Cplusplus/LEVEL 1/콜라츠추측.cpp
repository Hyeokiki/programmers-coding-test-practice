//22.01.21 콜라츠 추측 by CJHofficial

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    while (n != 1) {
        if (answer > 500) return -1;
        n = (n % 2 == 0) ? (n / 2) : (n * 3 + 1);
        answer += 1;
    }

    return answer;
}