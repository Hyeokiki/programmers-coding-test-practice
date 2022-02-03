import sys

sys.setrecursionlimit(10 ** 6)

directionDict = {0:[-1, 0], 1:[0, 1], 2:[1, 0], 3:[0, -1]}

def solution(grid):
    global visited, answer
    answer = []
    visited = [[[0]*len(grid[0]) for i in range(len(grid))] for j in range(4)]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            for d in range(4):
                dfs([i,j,d], [i,j,d], 1, grid)
    return sorted(answer)

def dfs(now, original, count, grid):
    x, y, direction = now
    visited[direction][x][y] = 1
    nextX, nextY = changePosition(x, y, direction, grid)
    value = grid[nextX][nextY]
    direction = changeDirection(direction, value)
    
    if original[0] == nextX and original[1] == nextY and original[2] == direction:
        answer.append(count)
        return
    if not visited[direction][nextX][nextY]:
        dfs([nextX, nextY, direction], original, count+1, grid)

def changePosition(prevX, prevY, direction, grid):
    nextX = prevX + directionDict[direction][0]
    nextY = prevY + directionDict[direction][1]
    
    if nextX >= len(grid):
        nextX = 0
    elif nextX < 0:
        nextX = len(grid)-1
    if nextY >= len(grid[0]):
        nextY = 0
    elif nextY < 0:
        nextY = len(grid[0])-1
        
    return nextX, nextY

def changeDirection(direction,value):
    if value == 'S':
        return direction
    if direction == 2:
        if value == 'R':
            return 3
        else:
            return 1
    elif direction == 1:
        if value == 'R':
            return 2
        else:
            return 0
    elif direction == 0:
        if value == 'R':
            return 1
        else:
            return 3
    else:
        if value == 'R':
            return 0
        else:
            return 2

# 못 품.....
