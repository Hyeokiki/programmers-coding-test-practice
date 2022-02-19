#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int index = 0;
    int nameSize = name.size();
    int shift = nameSize - 1;
    string tempName(nameSize, 'A');
    for(int left = 0; left < nameSize; left++){
        answer += min(name[left] - tempName[left], 'Z'- name[left] + 1);
        index = left + 1;
        while(index < nameSize && name[index] == 'A') index += 1;
        shift = min(shift, left * 2 + nameSize - index);
        shift = min(shift, 2 * (nameSize - index) + left);
    }
    answer += shift;
    return answer;
}