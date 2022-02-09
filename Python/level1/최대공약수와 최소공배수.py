def solution(n, m):
    multiple = n * m
    while m != 0:
        tempM = m
        m = n % m
        n = tempM
    return [n, multiple // n]
