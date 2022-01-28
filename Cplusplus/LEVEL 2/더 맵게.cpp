//22.01.27 ´õ ¸Ê°Ô by CJHofficial

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> PQ;
    for (int i = 0; i < scoville.size(); i++)
        PQ.push(scoville[i]);

    while (PQ.top() < K && PQ.size() > 1) {
        int first, second;
        answer += 1;
        first = PQ.top();
        PQ.pop();
        second = PQ.top();
        PQ.pop();
        PQ.push(first + second * 2);
    }
    if (PQ.top() < K)
        return -1;
    return answer;
}