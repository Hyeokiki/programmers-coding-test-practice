def solution(arr, divisor):
    answer = [number for number in sorted(arr) if number % divisor == 0]
    return answer if len(answer) !=0 else [-1]

# return A or B => or연산자를 통해 A == False일 경우 B를 내보낼 수 있다.  
