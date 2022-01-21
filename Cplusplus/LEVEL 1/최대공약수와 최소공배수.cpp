//22.01.21 최대공약수와 최소공배수 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = 1;
    int maxP, minM;
    int temp = min(n, m);
    while (temp--) {
        if ((n % a == 0) && (m % a == 0)) maxP = a;
        a += 1;
    }
    minM = maxP * (n / maxP) * (m / maxP);
    answer.push_back(maxP);
    answer.push_back(minM);
    return answer;
}