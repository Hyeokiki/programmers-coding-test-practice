//22.01.24 오픈채팅방 by CJHofficial

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> MAP;
    vector<pair<int, string>> transformVec; //0은 enter, 1은 leave, 2는 change를 뜻함.
    for (string s : record) {
        string arr[3];
        istringstream stt(s);
        stt >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] == "Enter") {
            transformVec.push_back(pair<int, string>(0, arr[1]));
            MAP[arr[1]] = arr[2];
        }
        else if (arr[0] == "Leave") {
            transformVec.push_back(pair<int, string>(1, arr[1]));
        }
        else if (arr[0] == "Change") {
            transformVec.push_back(pair<int, string>(2, arr[1]));
            MAP[arr[1]] = arr[2];
        }
    }
    for (auto p : transformVec) {
        string temp = "";
        if (p.first == 0) {
            temp += MAP[p.second] + "님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if (p.first == 1) {
            temp += MAP[p.second] + "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    return answer;
}