def solution(numbers):
    answer = []
    for first in range(len(numbers)-1):
        for second in range(first+1,len(numbers)):
            if numbers[first] + numbers[second] not in answer:
                answer.append(numbers[first] + numbers[second])
    return sorted(answer)
