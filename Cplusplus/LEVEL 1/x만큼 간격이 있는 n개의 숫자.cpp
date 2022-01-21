//22.01.22 x만큼 간격이 있는 n개의 숫자 by CJHofficial

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long step = x;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += step;
        answer.push_back(sum);
    }
    return answer;
}