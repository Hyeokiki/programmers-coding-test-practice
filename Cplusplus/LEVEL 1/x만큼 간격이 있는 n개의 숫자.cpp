//22.01.22 x��ŭ ������ �ִ� n���� ���� by CJHofficial

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