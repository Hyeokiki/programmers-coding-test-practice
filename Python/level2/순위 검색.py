from itertools import combinations

def solution(info, query):
    answer = []
    newInfo = {}
    for oneInfo in info:
        temp = oneInfo.split()
        conditions = temp[:-1]
        score = int(temp[-1])  
        for index in range(5):
            for combination in combinations(range(4), index):
                copiedCondition = conditions.copy()
                for v in combination:
                    copiedCondition[v] = '-'
                newKey = ' '.join(copiedCondition)
                if newKey in newInfo:
                    newInfo[newKey].append(score)
                else:
                    newInfo[newKey] = [score] 
    for value in newInfo.values():
        value.sort()
    for oneQuery in query:
        oneQuery = oneQuery.replace(' and ',' ').split(' ')
        count = 0
        key = ' '.join(oneQuery[:-1])
        score = int(oneQuery[-1])
        if key in newInfo:
            datas = newInfo[key]
            start, end = 0, len(datas)
            while start != end and start != len(datas):
                if int(datas[(start + end) // 2]) >= score:
                    end = (start + end) // 2
                else:
                    start = (start + end) // 2 + 1
            answer.append(len(datas) - start)
        else:
            answer.append(0)
    return answer
