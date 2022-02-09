def solution(progresses, speeds):
    answer = []
    stack = []
    for index, progress in enumerate(progresses):
        days = 0
        while progress + days * speeds[index] < 100:
            days += 1
        if len(stack) == 0:
            stack.append(days)
        else:
            if stack[0] >= days:
                stack.append(days)
            else:
                answer.append(len(stack))
                stack = [days]
    if len(stack):
        answer.append(len(stack))
    return answer
