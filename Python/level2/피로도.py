from itertools import permutations

def solution(k, dungeons):
    answer = -1
    array = []
    for dungeonList in permutations(dungeons,len(dungeons)):
        health = k
        count = 0
        for dungeon in dungeonList:
            if health >= dungeon[0]:
                health -= dungeon[1]
                count += 1
        answer = max(answer,count)
    return answer
