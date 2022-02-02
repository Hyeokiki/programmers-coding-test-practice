from itertools import combinations

def solution(places):
    answer = []
    for place in places:
        positions = [[row,col] for col in range(5) for row in range(5) if place[row][col] == 'P']
        for pair in combinations(positions,2):
            first, second = pair
            minX, maxX, minY, maxY = min(first[0],second[0]), max(first[0],second[0]), min(first[1],second[1]), max(first[1],second[1])
            if maxX - minX + maxY - minY == 2:
                if minX == maxX:
                    if place[minX][minY + 1] != 'X':
                        answer.append(0)
                        break
                elif minY == maxY:
                    if place[minX + 1][minY] != 'X':
                        answer.append(0)
                        break
                else:
                    if minX == first[0]:
                        if place[maxX][minY] != 'X' or place[minX][maxY] != 'X':
                            answer.append(0)
                            break
                    else:
                        if place[minX][minY] != 'X' or place[maxX][maxY] != 'X':
                            answer.append(0)
                            break
            if maxX - minX + maxY - minY == 1:
                answer.append(0)
                break
        else:
            answer.append(1)
    return answer
