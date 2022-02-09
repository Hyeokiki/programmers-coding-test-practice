def solution(maps):
    answer = 0
    visited = [[0] * len(maps[0]) for i in range(len(maps))]
    visited[0][0] = 1
    n, m = len(maps) - 1, len(maps[0]) - 1
    bfs = [[0, 0, 1]]
    x, y = 0, 0
    while len(bfs) and not (x == n and y == m):
        x, y, count = bfs.pop(0)
        if x - 1 >= 0 and maps[x - 1][y] and not visited[x - 1][y]:
            visited[x - 1][y] = 1
            bfs.append([x - 1, y, count + 1])
        if x + 1 <= n and maps[x + 1][y] and not visited[x + 1][y]:
            visited[x + 1][y] = 1
            bfs.append([x + 1, y, count + 1])
        if y - 1 >= 0 and maps[x][y - 1] and not visited[x][y - 1]:
            visited[x][y - 1] = 1
            bfs.append([x, y - 1, count + 1])
        if y + 1 <= m and maps[x][y + 1] and not visited[x][y + 1]:
            visited[x][y + 1] = 1
            bfs.append([x, y + 1, count + 1])
        answer = count
    if not (x == n and y == m):
        answer = -1
    return answer
