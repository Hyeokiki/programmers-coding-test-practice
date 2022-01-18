numToDirection = {1:'L',4:'L',7:'L',3:'R',6:'R',9:'R'}
numToLocation = {1:[0,0],2:[0,1],3:[0,2],4:[1,0],5:[1,1],6:[1,2],7:[2,0],8:[2,1],9:[2,2],'*':[3,0],0:[3,1],'#':[3,2]}
def solution(numbers, hand):
    answer = ''
    leftNow = '*'
    rightNow = '#'
    for number in numbers:
        if number in numToDirection.keys():
            answer = answer + numToDirection[number]
        else:
            [leftX,leftY] = numToLocation[leftNow]
            [rightX,rightY] = numToLocation[rightNow]
            [numberX,numberY] = numToLocation[number]
            left = abs(numberX-leftX) + abs(numberY-leftY)
            right = abs(numberX-rightX) + abs(numberY-rightY)
            if left < right:
                answer += 'L'
            elif left > right:
                answer += 'R'
            else:
                answer += hand[0].upper()
        if answer[-1] == 'L':
            leftNow = number
        else:
            rightNow = number
    return answer
