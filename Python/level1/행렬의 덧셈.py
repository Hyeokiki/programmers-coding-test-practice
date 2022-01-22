def solution(arr1, arr2):
    answer = []
    for first in range(len(arr1)):
        answer.append([])
        for second in range(len(arr1[first])):
            answer[first].append(arr1[first][second] + arr2[first][second])
    return answer
