//22.01.18 ���ڿ� ������������ ��ġ�ϱ� by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}