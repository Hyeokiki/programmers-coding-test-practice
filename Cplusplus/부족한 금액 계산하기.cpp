//22.01.13 부족한 금액 계산하기 by CJHofficial

using namespace std;

long long solution(int price, int money, int count)
{
    long long int answer = -1;
    long long int sum = 0;
    for (int i = 1; i <= count; i++) sum += i * price;
    if (money < sum) answer = sum - money;
    else answer = 0;
    return answer;
}