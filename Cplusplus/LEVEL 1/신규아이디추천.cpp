//22.01.04 신규 아이디 추천 by CJHofficial

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool IsTargetRemove(char c) {
    if ((c >= 97) && (c <= 122)) {
        return false;
    }
    else if ((c >= 48) && (c <= 57)) {
        return false;
    }
    else if (c == '-' || c == '_' || c == '.') {
        return false;
    }
    else {
        return true;
    }
}

string solution(string new_id) {
    string answer = "";
    answer = new_id;

    //1단계 모든 대문자를 대응되는 소문자로 치환
    for (int i = 0; i < answer.size(); i++) {
        answer[i] = tolower(answer[i]);
    }

    //2단계 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
    answer.erase(remove_if(answer.begin(), answer.end(), &IsTargetRemove), answer.end());

    //3단계 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
    while (answer.find("..") != string::npos) {
        int pos = answer.find("..");
        answer.replace(pos, 2, ".");
    }

    //4단계 마침표(.)가 처음이나 끝에 위치한다면 제거
    if (answer.front() == '.') {
        answer.erase(0, 1);
    }
    if (answer.back() == '.') {
        answer.erase((answer.size() - 1), 1);
    }

    //5단계 빈 문자열이라면 "a"를 대입
    if (answer.size() == 0) {
        answer = "a";
    }

    //6단계 길이가 16자 이상이면, 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거 만약 제거 후 마침표(.)가 끝에 위치한다면         끝에 위치한 마침표(.) 문자를 제거합니다.
    if (answer.size() >= 16) {
        answer.erase(15, (answer.size() - 15));
    }
    if (answer.back() == '.') {
        answer.erase((answer.size() - 1), 1);
    }

    //7단계 길이가 2자 이하라면, 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if (answer.size() <= 2) {
        while (answer.size() != 3) {
            answer += answer.back();
            //answer.append(1, answer.back()); 이렇게도 가능
        }
    }
    return answer;
}