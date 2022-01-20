//22.01.14 [1차]비밀지도 by CJHofficial
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int map1[n][n];
    int map2[n][n];
    vector<int> s1, s2;
    string s3;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            map1[i][j] = arr1[i] % 2;
            map2[i][j] = arr2[i] % 2;
            arr1[i] /= 2;
            arr2[i] /= 2;
        }
        for (int j = 0; j < n; j++) {
            if ((map1[i][j] == 1) || (map2[i][j] == 1)) s3 += "#";
            else s3 += " ";
        }
        answer.push_back(s3);
        s3 = "";
    }
    return answer;
}