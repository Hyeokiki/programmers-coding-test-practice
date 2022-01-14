def solution(sizes):
    answer = [0,0]
    for array in sizes:
        array.sort()
        answer[0] = answer[0] if answer[0] > array[0] else array[0]
        answer[1] = answer[1] if answer[1] > array[1] else array[1]
    return answer[0] * answer[1]
