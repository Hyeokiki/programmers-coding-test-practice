//22.02.01 °ýÈ£ º¯È¯ by CJHofficial

#include <string>
#include <vector>
using namespace std;

bool isRight(string target) {
    int check = 0;
    for (int i = 0; i < target.size(); i++) {
        if (target[i] == '(') check += 1;
        else if (target[i] == ')') check -= 1;
        if (check < 0) return false;
    }
    return true;
}

string dfs(string w) {
    if (w == "") return "";
    string u = "";
    string v = "";
    int count = 0;
    int vindex = w.size();
    for (int i = 0; i < w.size(); i++) {
        u += w[i];
        if (w[i] == '(') count += 1;
        if (w[i] == ')') count -= 1;
        if (count == 0) {
            vindex = i + 1;
            break;
        }
    }
    for (int j = vindex; j < w.size(); j++) v += w[j];
    if (isRight(u)) {
        u += dfs(v);
        return u;
    }
    else {
        string temp = "";
        temp += "(";
        temp += dfs(v);
        temp += ")";
        for (int i = 1; i < u.size() - 1; i++) {
            temp += (u[i] == '(') ? ')' : '(';
        }
        return temp;
    }
}
string solution(string p) {
    string answer = "";
    answer = dfs(p);
    return answer;
}