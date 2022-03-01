import math

def solution(brown, yellow):
    total = brown + yellow
    for number in range(3, int(math.sqrt(total)) + 1):
        if total / number == total // number:
            if (number - 2) * (total // number - 2) == yellow:
                return [total // number, number]
