def solution(absolutes, signs):
    answer = 0
    for index in range(len(absolutes)):
        answer += absolutes[index] if signs[index] else -absolutes[index]
    return answer
