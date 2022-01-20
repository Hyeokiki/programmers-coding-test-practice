//22.01.11 3진법 뒤집기 by CJHofficial

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> list;
    while (n > 0) {
        list.push_back(n % 3);
        n = n / 3;
    }
    int size = list.size();

    for (int i = 0; i < size; i++) {
        answer += list[size - (1 + i)] * pow(3, i);
    }
    return answer;
}