//22.01.21 ÇÏ»þµå ¼ö by CJHofficial

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int y = x;
    int num = 0;
    while (y > 0) {
        num += y % 10;
        y /= 10;
    }
    return (x % num == 0);
}