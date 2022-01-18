def solution(price, money, count):
    total = sum(index for index in range(1,count + 1))
    return price * total - money if price * total > money else 0
