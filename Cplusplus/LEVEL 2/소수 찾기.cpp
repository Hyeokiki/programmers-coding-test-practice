//22.02.08 소수 찾기 by CJHofficial

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool checkPrime(int num) {
    if (num == 0 || num == 1) return false;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector<int> answerList;
    sort(numbers.begin(), numbers.end());
    for (int i = 1; i <= numbers.size(); i++) {
        vector<bool> picked(numbers.size(), false);
        for (int j = 0; j < i; j++) picked[j] = true;
        do {
            string temp = "";
            for (int j = 0; j < numbers.size(); j++) {
                if (picked[j]) temp += numbers[j];
            }
            int num = stoi(temp);
            if (checkPrime(num)) answerList.push_back(num);
        } while (next_permutation(numbers.begin(), numbers.end()));
    }
    sort(answerList.begin(), answerList.end());
    answerList.erase(unique(answerList.begin(), answerList.end()), answerList.end());
    answer = answerList.size();
    return answer;
}