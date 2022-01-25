#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int check[102][102] = { 0, };
int pic[102][102] = { 0, };
int NUM = 0;

void dfs(int mindex, int nindex, int& target) {
    if (pic[mindex][nindex] == 0) return;
    if ((check[mindex][nindex] == 0) && (pic[mindex][nindex] == target)) {
        check[mindex][nindex] = 1;
        NUM += 1;
        dfs(mindex - 1, nindex, target);
        dfs(mindex + 1, nindex, target);
        dfs(mindex, nindex - 1, target);
        dfs(mindex, nindex + 1, target);
    }
    return;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int COUNT = 0;
    int max_area = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pic[i + 1][j + 1] = picture[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (check[i][j]) continue;
            dfs(i, j, pic[i][j]);
            if (NUM > 0) {
                COUNT++;
                max_area = max(max_area, NUM);
            }
            NUM = 0;
        }
    }
    vector<int> answer(2);
    answer[0] = COUNT;
    answer[1] = max_area;
    return answer;
}

/*
   1 1 1 0     1 1 1 0
   1 1 1 0     1 2 2 0
   0 0 0 1     1 0 0 1
   0 0 0 1     0 0 0 1
   0 0 0 1     0 0 0 3
   0 0 0 1     0 0 0 3
*/