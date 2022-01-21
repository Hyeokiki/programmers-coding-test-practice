//22.01.21 Æò±Õ ±¸ÇÏ±â by CJHofficial

#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    answer = sum / arr.size();
    return answer;
}