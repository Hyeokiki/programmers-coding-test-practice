#include <string>
#include <vector>

using namespace std;
int arr[102][102] = { 0, };

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            queries[i][j] = j + 6 * (i - 1);
        }
    }
    int startRow, startCol;
    int finalRow, finalCol;
    for (auto v : queries) {
        startRow = v[0];
        startCol = v[1];
        for (int i = startCol; i < v.size(); i++) {

        }
    }
    return answer;
}