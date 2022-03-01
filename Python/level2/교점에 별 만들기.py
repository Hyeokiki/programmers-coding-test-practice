from itertools import combinations

def solution(line):
    answer = []
    pos = []
    INF = float('inf')
    minX,minY,maxX,maxY = INF,INF,-INF,-INF
    for first,second in combinations(line,2):
        a1, b1, c1 = first
        a2, b2, c2 = second
        if a1*b2 == a2 * b1:
            continue
            
        x = (b1*c2-b2*c1)/(a1*b2-a2*b1)
        y = (a1*c2-a2*c1)/(a2*b1-a1*b2)
        if x == int(x) and y == int(y):
            x,y = int(x),int(y)
            pos.append([x,y])
            minX,minY,maxX,maxY=min(minX,x),min(minY,y),max(maxX,x),max(maxY,y)
    for y in range(minY,maxY+1):
        answer.insert(0,'')
        for x in range(minX,maxX+1):
            if [x,y] in pos:
                answer[0]+='*'
            else:
                answer[0]+='.'
    return answer
