import re

def solution(s):
    answer = []
    tuples = re.compile('.+?}').findall(s)
    tuples = [re.sub('[{}]', '', string).split(',') for string in tuples]
    tuples = [[int(value) for value in values if value] for values in tuples]
    tuples.sort(key = lambda x: len(x))
    for values in tuples:
        for value in values:
            if value not in answer:
                answer.append(value)
    return answer
