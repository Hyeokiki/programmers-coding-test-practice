def solution(n):
    answer = []
    triangle = [[0 for i in range(j)] for j in range(1,n+1)]
    i, j, number = 0, 0, 1
    flag = 0
    countForFlag = 0
    while i >= j and triangle[i][j] == 0:
        triangle[i][j] = number
        countForFlag += 1
        if countForFlag == n:
            flag = flag + 1 if flag != 2 else 0
            n -= 1
            countForFlag = 0
        
        if flag == 0:
            i += 1
        elif flag == 1:
            j += 1
        else:
            i -= 1
            j -= 1
            
        number += 1
    
    for array in triangle:
        for number in array:
            answer.append(number)
    return answer
