//22.01.18 ���ڼ��ڼ��ڼ��ڼ��ڼ�? by CJHofficial

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string SUBAK[2] = { "��","��" };
    for (int i = 0; i < n; i++) answer += SUBAK[i % 2];

    return answer;
}