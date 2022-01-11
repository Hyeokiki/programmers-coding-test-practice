def solution(n):
    answer = ''
    while n != 0:
        div = n % 3
        n = n // 3
        answer += str(div)
    return int(answer,3)
