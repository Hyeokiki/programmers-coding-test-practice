//22.01.13 최소직사각형 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxWidth = 0;
    int maxHeight = 0;
    for (auto v : sizes) {
        sort(v.begin(), v.end());
        if (v[0] > maxWidth) maxWidth = v[0];
        if (v[1] > maxHeight) maxHeight = v[1];
    }
    answer = maxWidth * maxHeight;
    return answer;
}