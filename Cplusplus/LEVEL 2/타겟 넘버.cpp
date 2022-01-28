//22.01.28 Å¸°Ù ³Ñ¹ö by CJHofficial

#include <string>
#include <vector>

using namespace std;
int answer = 0;
int numSize = 0;
int T = 0;
vector<int> numVec;

void dfs(int index, int sum) {
    if (index == (numSize - 1)) {
        if (sum == T) answer += 1;
        return;
    }
    dfs(index + 1, sum + numVec[index + 1]);
    dfs(index + 1, sum - numVec[index + 1]);
}

int solution(vector<int> numbers, int target) {
    numVec = numbers;
    numSize = numbers.size();
    T = target;
    dfs(-1, 0);

    return answer;
}