//22.01.17 문자열 내 p와 y의 개수 by CJHofficial
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int check[2] = { 0 ,0 }; //p,y
    for (auto c : s) {
        if (c == 'p' || c == 'P') check[0]++;
        if (c == 'y' || c == 'Y') check[1]++;
    }
    if ((check[0] == 0) && (check[1] == 0)) return true;
    return check[0] == check[1];
}