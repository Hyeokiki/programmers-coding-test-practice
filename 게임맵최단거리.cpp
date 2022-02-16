#include <vector>
#include <queue>

using namespace std;

struct pos{
    int y;
    int x;
    pos(int tempy, int tempx) {y = tempy; x = tempx;}
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<int>> distance(n, vector<int>(m));
    queue<pos> Q;
    
    int moveY[4] = {-1, 0, 1, 0};
    int moveX[4] = {0, 1, 0, -1};
    
    Q.push(pos(0, 0));
    visited[0][0] = true;
    distance[0][0] = 1;
    
    while(!Q.empty()){
        pos p = Q.front();
        Q.pop();
        int nowY = p.y;
        int nowX = p.x;
        
        for(int i = 0; i < 4; i++){
            int nextY = nowY + moveY[i];
            int nextX = nowX + moveX[i];
            
            if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;
            if(maps[nextY][nextX] == 0) continue;
            if(visited[nextY][nextX]) continue;
            
            Q.push(pos(nextY, nextX));
            visited[nextY][nextX] = true;
            distance[nextY][nextX] = distance[nowY][nowX] + 1;
        }
    }
    if(visited[n-1][m-1]) answer = distance[n-1][m-1];
    
    return answer;
}