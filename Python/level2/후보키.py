from itertools import combinations

def solution(relation):
    answer = 0
    length = 1
    candidates = []
    
    while length <= len(relation[0]):
        for combination in combinations(range(len(relation[0])), length):
            attributeDict = {}
            
            for row in relation:
                temp = []
                
                for attribute in combination:
                    temp.append(row[attribute])
                fullAttribute = ''.join(temp)
                
                if fullAttribute in attributeDict:
                    break
                else:
                    attributeDict[fullAttribute] = 1
            else:
                if len(candidates) == 0:
                    candidates.append(set(combination))
                else:
                    for candidate in candidates:
                        if set(combination) > candidate:
                            break
                    else:
                        candidates.append(set(combination))
        length += 1
            
    return len(candidates)
