def solution(x):
    return x % sum([int(number) for number in str(x)]) == 0
