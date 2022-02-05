//22.02.01 행렬 테두리 회전하기 by CJHofficial

#include <string>
#include <vector>

using namespace std;

int arr[102][102] = { 0, };

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = j + columns * (i - 1);
        }
    }
    int startRow, startCol, finalRow, finalCol, temp1, temp2;
    for (auto v : queries) {
        startRow = v[0]; startCol = v[1]; finalRow = v[2]; finalCol = v[3];
        temp1 = arr[startRow][startCol];
        int min = temp1;
        for (int j = startCol; j < finalCol; j++) {
            if (min > temp1) min = temp1;
            temp2 = arr[startRow][j + 1];
            arr[startRow][j + 1] = temp1;
            temp1 = temp2;
        }
        for (int i = startRow; i < finalRow; i++) {
            if (min > temp1) min = temp1;
            temp2 = arr[i + 1][finalCol];
            arr[i + 1][finalCol] = temp1;
            temp1 = temp2;
        }
        for (int j = finalCol; j > startCol; j--) {
            if (min > temp1) min = temp1;
            temp2 = arr[finalRow][j - 1];
            arr[finalRow][j - 1] = temp1;
            temp1 = temp2;
        }
        for (int i = finalRow; i > startRow; i--) {
            if (min > temp1) min = temp1;
            temp2 = arr[i - 1][startCol];
            arr[i - 1][startCol] = temp1;
            temp1 = temp2;
        }
        answer.push_back(min);
    }
    return answer;
}