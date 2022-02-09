def solution(n):
    return sum([number for number in range(1,int(n + 1)) if n % number == 0])
