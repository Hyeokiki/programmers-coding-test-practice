//22.01.18 소수찾기 by CJHofficial

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int prime[n + 1];
    for (int i = 2; i <= n; i++) prime[i] = 1;
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) continue;
        for (int j = i * 2; j <= n; j += i) {
            prime[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] != 0) answer += 1;
    }
    return answer;
}