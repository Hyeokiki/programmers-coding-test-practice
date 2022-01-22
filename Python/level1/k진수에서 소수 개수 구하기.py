def solution(n, k):
    answer = 0
    string = ''
    while n != 0:
        string = str(n % k) + string
        n = n // k
    arraySplitedByZero = string.split('0')
    for item in arraySplitedByZero:
        if item == '':
            continue
        for number in range(2,int(int(item) ** (1/2)) + 1):
            if int(item) % number == 0:
                break
        else:
            if item != '1':
                answer += 1
    return answer
