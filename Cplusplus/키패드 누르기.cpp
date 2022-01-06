//22.01.05 Ű�е� ������ by CJHofficial

#include <string>
#include <vector>
#include <utility>
#include <cmath>


using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    //*�� 10, #�� 11
    int lastLeft = 10;
    int lastRight = 11;
    int leftD = 0;  //���� ���������� �Ÿ�
    int rightD = 0; //������ ���������� �Ÿ�
    pair<int, int> keyPad[12]; //�� �迭�� index�� Ű�е��� ������, pair���� ��ġ ����

    keyPad[0] = { 3,1 };
    keyPad[10] = { 3,0 };
    keyPad[11] = { 3,2 };

    //keyPad��ġ �ʱ�ȭ
    for (int i = 1; i < 10; i++) {
        keyPad[i] = { ((i - 1) / 3), ((i - 1) % 3) };
    }

    //���ڿ� �����
    int check = 0; //check�� -1�̸� ����, check�� 1�̸� ������
    for (int i : numbers) {
        if (i == 1 || i == 4 || i == 7) {
            check = -1;
        }
        else if (i == 3 || i == 6 || i == 9) {
            check = 1;
        }
        else {
            leftD = abs(keyPad[i].first - keyPad[lastLeft].first) + abs(keyPad[i].second - keyPad[lastLeft].second);
            rightD = abs(keyPad[i].first - keyPad[lastRight].first) + abs(keyPad[i].second - keyPad[lastRight].second);
            if (leftD < rightD) {
                check = -1;
            }
            else if (leftD > rightD) {
                check = 1;
            }
            else {
                if (hand == "right") {
                    check = 1;
                }
                else if (hand == "left") {
                    check = -1;
                }
            }
        }
        if (check == -1) {
            answer += "L";
            lastLeft = i;
        }
        else if (check == 1) {
            answer += "R";
            lastRight = i;
        }
    }

    return answer;
}