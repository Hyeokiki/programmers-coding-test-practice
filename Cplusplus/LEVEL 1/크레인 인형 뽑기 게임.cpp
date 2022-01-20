//22.01.05 크레인 인형 뽑기 게임 by CJHofficial

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for (int num : moves) {
        for (int i = 0; i < board.size(); i++) {
            int target = board[i][num - 1]; //뽑을 숫자
            if (target == 0) {
            }
            else {
                board[i][num - 1] = 0;
                if (!s.empty() && (s.top() == target)) {
                    s.pop();
                    answer += 2;
                }
                else {
                    s.push(target);
                }
                break;
            }

        }
    }
    return answer;
}