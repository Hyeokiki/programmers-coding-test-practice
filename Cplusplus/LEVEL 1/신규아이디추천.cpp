//22.01.04 �ű� ���̵� ��õ by CJHofficial

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

    //1�ܰ� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ
    for (int i = 0; i < answer.size(); i++) {
        answer[i] = tolower(answer[i]);
    }

    //2�ܰ� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� ����
    answer.erase(remove_if(answer.begin(), answer.end(), &IsTargetRemove), answer.end());

    //3�ܰ� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ
    while (answer.find("..") != string::npos) {
        int pos = answer.find("..");
        answer.replace(pos, 2, ".");
    }

    //4�ܰ� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� ����
    if (answer.front() == '.') {
        answer.erase(0, 1);
    }
    if (answer.back() == '.') {
        answer.erase((answer.size() - 1), 1);
    }

    //5�ܰ� �� ���ڿ��̶�� "a"�� ����
    if (answer.size() == 0) {
        answer = "a";
    }

    //6�ܰ� ���̰� 16�� �̻��̸�, ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� ���� ���� ���� �� ��ħǥ(.)�� ���� ��ġ�Ѵٸ�         ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
    if (answer.size() >= 16) {
        answer.erase(15, (answer.size() - 15));
    }
    if (answer.back() == '.') {
        answer.erase((answer.size() - 1), 1);
    }

    //7�ܰ� ���̰� 2�� ���϶��, ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
    if (answer.size() <= 2) {
        while (answer.size() != 3) {
            answer += answer.back();
            //answer.append(1, answer.back()); �̷��Ե� ����
        }
    }
    return answer;
}