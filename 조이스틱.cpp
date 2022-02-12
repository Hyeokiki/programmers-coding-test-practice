#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int index = 0;
    int nameSize = name.size();
    string nameVec(nameSize, 'A');
    for(int i = 0; i < nameSize; i++){
        answer += min(abs(nameVec[i] - name[i]), abs('Z'- name[i]) + 1);
    }
    cout << answer ;
    while(true){
        nameVec[index] = name[index];
        if(nameVec == name) break;
        for(int i = 1; i < nameSize; i++){
            if(nameVec[(index + i) % nameSize] != name[(index + i) % nameSize]){
                index += i;
                index %= nameSize;
                answer += i;
                break;
            }
            else if(nameVec[(index - i + nameSize) % nameSize] != name[(index - i + nameSize) % nameSize]){
                index -= i;
                index += nameSize;
                index %= nameSize;
                answer += i;
                break;
            }
        }
    }
    
    
    return answer;
}