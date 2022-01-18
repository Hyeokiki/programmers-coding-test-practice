import re
square = {'S':1,'D':2,'T':3}
def solution(dartResult):
    answer = []
    scores = re.compile('\d+[SDT][*#]*').findall(dartResult)
    for score in scores:
        number = re.search('\d+', score).group()
        word = re.search('[SDT]', score).group()
        option = re.search('[*#]', score)
        realScore = int(number) ** square[word]
        if option:
            if option.group() == '*':
                realScore = realScore * 2
                if len(answer) != 0:
                    answer[-1] = answer[-1] * 2
            elif option.group() == '#':
                realScore = -realScore
        answer.append(realScore)
    return sum(answer)
