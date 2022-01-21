//22.01.22 ����� ���� by CJHofficial

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int rowSize = arr1.size();
    int colSize = arr1[0].size();
    for (int i = 0; i < rowSize; i++) {
        vector<int> v;
        for (int j = 0; j < colSize; j++) {
            v.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(v);
    }
    return answer;
}