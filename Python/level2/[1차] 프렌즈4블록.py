def solution(m, n, board):
    answer = 0
    flag = True
    board = [[board[len(board) - j - 1][i] for j in range(len(board))]for i in range(len(board[0]))]
    while True:
        flag = True
        eachRow = [[] for i in range(len(board))]
        
        for i in range(n - 1):
            for j in range(m - 1):
                if board[i][j] == board[i + 1][j] == board[i][j + 1] == board[i + 1][j + 1] != '0':
                    flag = False
                    eachRow[i].append(j)
                    eachRow[i].append(j+1)
                    eachRow[i+1].append(j)
                    eachRow[i+1].append(j+1)
        
        if flag:
            break
            
        for i in range(len(eachRow)):
            eachRow[i] = sorted(list(set(eachRow[i])))
            for index, column in enumerate(eachRow[i]):
                board[i].pop(column - index)
                board[i].append('0')
                answer+=1
    return answer
