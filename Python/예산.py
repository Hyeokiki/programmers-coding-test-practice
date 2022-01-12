def solution(d, budget):
    answer = 0
    for money in sorted(d):
        budget -= money
        if budget < 0:
            break
        answer += 1
    return answer
