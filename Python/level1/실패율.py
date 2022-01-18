def solution(N, stages):
    total = len(stages)
    failPercentage = []
    for stage in range(1, N+1):
        if total != 0:
            count = stages.count(stage)
            failPercentage.append(count / total)
            total -= count
        else:
            failPercentage.append(0)
    sortedFailPercentage = sorted(failPercentage, reverse = True)
    answer = []
    for stage in sortedFailPercentage:
        index = failPercentage.index(stage)
        answer.append(index + 1)
        failPercentage[index] = -1
    return answer
