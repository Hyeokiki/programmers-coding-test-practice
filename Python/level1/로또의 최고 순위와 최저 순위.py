def solution(lottos, win_nums):
    erasedNumberCount = countErasedNumber(lottos)
    minRanking = countSameNumber(lottos,win_nums)
    maxRanking = minRanking + erasedNumberCount
    answer = [changeRanking(maxRanking), changeRanking(minRanking)]
    return answer

def countErasedNumber(lottos):
    count = 0
    for lottoNumber in lottos:
        if lottoNumber == 0:
            count = count + 1
    return count

def countSameNumber(lottos,win_nums):
    count = 0
    for lotto in lottos:
        if lotto in win_nums:
            count = count + 1
    return count

def changeRanking(sameNumber):
    ranking = 6
    if sameNumber == 2:
        ranking=5
    elif sameNumber == 3:
        ranking=4
    elif sameNumber == 4:
        ranking=3
    elif sameNumber == 5:
        ranking=2
    elif sameNumber == 6:
        ranking=1
    return ranking
