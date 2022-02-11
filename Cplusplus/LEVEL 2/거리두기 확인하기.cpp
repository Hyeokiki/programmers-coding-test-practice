//22.02.02 거리두기 확인하기 by CJHofficial

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int roomArr[9][9] = { 0, }; //P => 1, O => 0, X => -1
bool visitedArr[9][9] = { false, }; //true => 방문한 곳
int flag = 1;

void dfs(int row, int col, int step) {
    if (step > 2) return;
    if (visitedArr[row][col]) return;
    else visitedArr[row][col] = true;
    if (roomArr[row][col] < 0) {
        return;
    }
    else if (roomArr[row][col] > 0 && step >= 1) {
        flag = -1;
        return;
    }
    else {
        dfs(row - 1, col, step + 1);
        dfs(row + 1, col, step + 1);
        dfs(row, col - 1, step + 1);
        dfs(row, col + 1, step + 1);
        return;
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto room : places) {
        int rowIndex = 2;
        int colIndex = 2;
        for (auto row : room) {
            for (int i = 0; i < row.size(); i++) {
                if (row[i] == 'X') {
                    roomArr[rowIndex][colIndex++] = -1;
                }
                else if (row[i] == 'P') {
                    roomArr[rowIndex][colIndex++] = 1;
                }
                else roomArr[rowIndex][colIndex++] = 0;
            }
            colIndex = 2;
            rowIndex += 1;
        }
        for (int i = 2; i < 7; i++) {
            for (int j = 2; j < 7; j++) {
                if (roomArr[i][j] == 1) dfs(i, j, 0);
                fill(visitedArr[0], visitedArr[10], false);
            }
        }
        if (flag < 0) answer.push_back(0);
        else if (flag > 0) answer.push_back(1);
        flag = 1;
    }
    return answer;
}