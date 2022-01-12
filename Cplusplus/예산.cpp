//22.01.12 ¿¹»ê by CJHofficial
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(), d.end());
    for (int i : d) {
        if (sum + i > budget) break;
        sum += i;
        answer += 1;
    }
    return answer;
}