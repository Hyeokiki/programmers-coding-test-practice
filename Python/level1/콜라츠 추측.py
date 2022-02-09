def solution(num):
    answer = 0
    for index in range(500):
        if num == 1:
            answer = index
            break
        num = num // 2 if num % 2 == 0 else num * 3 + 1
    else:
        answer = -1
    return answer
