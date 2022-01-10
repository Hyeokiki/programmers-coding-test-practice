//22.01.10 ÆùÄÏ¸ó by CJHofficial

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int temp = -1;
    sort(nums.begin(), nums.end());
    for (int i : nums) {
        if (answer == (nums.size() / 2)) break;
        if (temp != i) {
            temp = i;
            answer += 1;
        }
    }
    return answer;
}