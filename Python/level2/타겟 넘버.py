def solution(numbers, target):
    answer = dfs(numbers, target, 0, 0)
    return answer

def dfs(numbers, target, now, index):
    total = 0
    number = numbers[index]
    if len(numbers) - 1 == index:
        if now + number == target:
            total += 1
        if now - number == target:
            total += 1
    else:
        total += dfs(numbers, target, now + number, index + 1)
        total += dfs(numbers, target, now - number, index + 1)
    return total

# Python 순열, 조합, product - itertools
# from itertools import product
# def solution(numbers, target):
#     l = [(x, -x) for x in numbers]
#     s = list(map(sum, product(*l)))
#     return s.count(target)
