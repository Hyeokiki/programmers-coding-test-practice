//22.01.26 멀쩡한 사각형 by CJHofficial

#include <iostream>
using namespace std;


long long solution(int w, int h) {
    long long answer = 0;
    long long y;
    for (int i = 1; i < w; i++) {
        y = (double)h / w * i * (-1.0) + h;
        answer += (int)y;
    }
    return answer * 2;
}