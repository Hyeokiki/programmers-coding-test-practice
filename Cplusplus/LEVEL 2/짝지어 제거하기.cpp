//22.01.28 짝지어 제거하기 by CJHofficial

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    for (auto c : s) {
        if (!st.empty()) {
            if (st.top() == c) st.pop();
            else st.push(c);
        }
        else st.push(c);
    }
    return (st.empty()) ? 1 : 0;
}