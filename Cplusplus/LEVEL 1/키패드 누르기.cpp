//22.01.05 키패드 누르기 by CJHofficial

#include <string>
#include <vector>
#include <utility>
#include <cmath>


using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    //*은 10, #은 11
    int lastLeft = 10;
    int lastRight = 11;
    int leftD = 0;  //왼쪽 엄지에서의 거리
    int rightD = 0; //오른쪽 엄지에서의 거리
    pair<int, int> keyPad[12]; //이 배열의 index가 키패드의 숫자임, pair에는 위치 저장

    keyPad[0] = { 3,1 };
    keyPad[10] = { 3,0 };
    keyPad[11] = { 3,2 };

    //keyPad위치 초기화
    for (int i = 1; i < 10; i++) {
        keyPad[i] = { ((i - 1) / 3), ((i - 1) % 3) };
    }

    //문자열 만들기
    int check = 0; //check가 -1이면 왼쪽, check가 1이면 오른쪽
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