def solution(array, commands):
    answer = []
    for row in range(len(commands)):
        slicedArray = array[commands[row][0]-1:commands[row][1]]
        slicedArray.sort()
        answer.append(slicedArray[commands[row][2]-1])
    return answer
