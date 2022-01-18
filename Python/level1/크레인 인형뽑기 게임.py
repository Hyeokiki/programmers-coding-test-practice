def solution(board, moves):
    answer = 0
    size = len(board[0])
    tops = []
    basket = []
    for position in range(size):
        tops.append(findTop(board,position,size))
    for move in moves:
        if tops[move - 1] == size:
            continue
        positionDoll = board[tops[move - 1]][move - 1]
        tops[move - 1] += 1
        if not len(basket) == 0:
            basketDoll = basket.pop()
            if basketDoll == positionDoll:
                answer += 1
                continue
            else:
                basket.append(basketDoll)
        basket.append(positionDoll)
    return answer*2

def findTop(board,position,size):
    for index in range(size):
        if board[index][position] != 0:
            return index
    return size
