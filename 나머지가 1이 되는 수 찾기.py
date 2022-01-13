import math

def solution(n):
    answer = 0
    for number in range(2,int(math.sqrt(n - 1))+1):
        if (n - 1) % number == 0:
            answer = number
            break
    else:
        answer = n - 1
    return answer
