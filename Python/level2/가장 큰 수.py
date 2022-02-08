import functools

def comparator(first, second):
    return int(second + first) - int(first + second)

def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key = functools.cmp_to_key(comparator))
    return str(int(''.join(numbers)))

# 반환문을 int로 변환한 뒤 다시 string으로 변환해야하는 이유는 정확하게 알지 못하겠음
