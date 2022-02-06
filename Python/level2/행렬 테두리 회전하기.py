def solution(rows, columns, queries):
    answer = []
    number = 0
    array = [[row * columns + col for col in range(1, columns + 1)] for row in range(rows)]
    for query in queries:
        answer.append([])
        [leftX, leftY, rightX, rightY] = query
        [tempX, tempY] = [leftX, leftY]
        temp1 = array[tempX - 1][tempY - 1]
        answer[-1].append(temp1)
        for y in range(leftY, rightY):
            temp2 = array[leftX - 1][y]
            array[leftX - 1][y] = temp1
            temp1 = temp2
            answer[-1].append(temp1)
        for x in range(leftX, rightX):
            temp2 = array[x][rightY - 1]
            array[x][rightY - 1] = temp1
            temp1 = temp2
            answer[-1].append(temp1)
        for y in range(rightY - 2, leftY - 2, -1):
            temp2 = array[rightX - 1][y]
            array[rightX - 1][y] = temp1
            temp1 = temp2
            answer[-1].append(temp1)
        for x in range(rightX - 2, leftX - 2, -1):
            temp2 = array[x][leftY - 1]
            array[x][leftY - 1] = temp1
            temp1 = temp2
            answer[-1].append(temp1)
        answer[-1] = sorted(answer[-1])[0]
    return answer
