from queue import PriorityQueue

def solution(N, road, K):
    answer = 0
    minDistance = [1000000] * (N + 1)
    minDistance[1] = 0
    canGo = PriorityQueue()
    canGo.put([0,1])
    while not canGo.empty():
        distance, now = canGo.get()
        
        if minDistance[now] < distance:
            continue
        
        for oneRoad in road:
            realDistance = distance + oneRoad[2]
            if oneRoad[0] == now:
                if realDistance < minDistance[oneRoad[1]]:
                    canGo.put([realDistance, oneRoad[1]])
                    minDistance[oneRoad[1]] = realDistance
            elif oneRoad[1] == now:
                if realDistance < minDistance[oneRoad[0]]:
                    canGo.put([realDistance, oneRoad[0]])
                    minDistance[oneRoad[0]] = realDistance
    return len([index for index in range(N + 1) if minDistance[index] <= K])
