//22.01.18 ���ڿ� �ٷ�� �⺻ by CJHofficial

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if ((s.size() == 4) || (s.size() == 6)) {
        for (auto c : s) {
            if (c < '0' || c >'9') return false;
        }
        return true;
    }
    return false;
}