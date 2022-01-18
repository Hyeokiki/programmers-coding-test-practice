import math

def solution(left, right):
    answer = 0
    for number in range(left,right+1):
        answer += number if int(math.sqrt(number)) != math.sqrt(number) else -number
    return answer
