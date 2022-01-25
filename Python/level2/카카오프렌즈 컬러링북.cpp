#include <vector>
#include <queue>

using namespace std;

bool isItInside(int number, int max) {
    return number >=0 && number < max;
}

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    vector<int> answer(2);
    vector<vector<int> > visit(m, vector<int>(n));
    vector<int> direction = {-1,0,0,-1,0,1,1,0};
    int maxCount = 0;
    int areas = 0;
    for(int row = 0; row < m; row++) {
        for(int col = 0; col < n; col++) {    
            if(visit[row][col] == 0 && picture[row][col] != 0) {
                int now = picture[row][col];
                int count = 1;
                queue<pair<int, int> > myQueue;

                myQueue.push(make_pair(row,col));
                visit[row][col] = 1;
                while(!myQueue.empty()) {
                    int x = myQueue.front().first;
                    int y = myQueue.front().second;
                    myQueue.pop();
                    for(int d = 0; d < direction.size(); d += 2) {
                        int nowX = x + direction[d];
                        int nowY = y + direction[d + 1];
            
                        if(isItInside(nowX, m) && isItInside(nowY, n) && visit[nowX][nowY] == 0 && now == picture[nowX][nowY]) {
                            visit[nowX][nowY] = 1;
                            myQueue.push(make_pair(nowX,nowY));
                            count++;
                        }
                    }
                }
                maxCount = maxCount < count ? count:maxCount;
                areas++;
            }
        }
    }
    answer[0] = areas;
    answer[1] = maxCount;
    return answer;
}
