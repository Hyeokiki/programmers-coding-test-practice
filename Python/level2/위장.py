from collections import Counter

def solution(clothes):
    answer = 1
    clothDict = Counter([cloth[1] for cloth in clothes])
    for value in clothDict.values():
        answer = answer * (value + 1)
    return answer - 1
