//22.01.06 소수만들기 by CJHofficial

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool checkPrime(int sum) {
    for (int j = 2; j <= sqrt(sum); j++) {
        if ((sum % j) == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int numSize = nums.size();
    int sum = 0;
    for (int a = 0; a < numSize; a++) {
        for (int b = a + 1; b < numSize; b++) {
            for (int c = b + 1; c < numSize; c++) {
                sum = nums[a] + nums[b] + nums[c];
                if (checkPrime(sum)) answer += 1;
            }
        }
    }

    return answer;
}