def solution(n,a,b):
    answer = 0
    while a != b:
        answer += 1
        a = a / 2 if a % 2 == 0 else a // 2 + 1
        b = b / 2 if b % 2 == 0 else b // 2 + 1
    return answer
