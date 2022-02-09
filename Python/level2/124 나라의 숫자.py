newNumber = {0:'1',1:'2',2:'4'}

def solution(n):
    answer = ''
    while n > 3:
        answer = str(newNumber[(n - 1) % 3]) + answer
        n = (n - 1) // 3
    answer = str(newNumber[(n - 1) % 3]) + answer
    return answer
