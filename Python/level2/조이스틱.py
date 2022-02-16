def solution(name):
    return greedy(name, 'A'* len(name), 0, 0)

def greedy(name, temp, index, count):
    count += min(ord(name[index]) - ord('A'), ord('Z') - ord(name[index]) + 1)
    temp = temp[:index] + name[index] + temp[index + 1:]
        
    if temp == name:
        return count
            
    minusIndex = index - 1 if index - 1 >= 0 else len(name) - 1
    plusIndex = index + 1 if index + 1 < len(name) else 0
    minusCount, plusCount = 1, 1
    while temp[minusIndex] == name[minusIndex]:
        minusIndex = minusIndex - 1 if minusIndex - 1 >= 0 else len(name) - 1
        minusCount += 1
    while temp[plusIndex] == name[plusIndex]:
        plusIndex = plusIndex + 1 if plusIndex + 1 < len(name) else 0
        plusCount += 1
    return min(greedy(name, temp, plusIndex, count + plusCount), greedy(name, temp, minusIndex, count + minusCount))
