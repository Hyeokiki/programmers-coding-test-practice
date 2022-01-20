def solution(n):
    return (n ** (1/2) + 1) ** 2 if int(n**(1/2)) == n **(1/2) else -1
