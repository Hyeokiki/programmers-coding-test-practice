def solution(s):
    answer = len(s)
    for number in range(1, len(s) // 2 + 1):
        compression = ''
        stack = [s[:number]]
        tempS = s[number:]
        while len(tempS) >= number:
            string = tempS[:number]
            if stack[-1] == string:
                stack.append(string)
            else:
                compression += ('' if len(stack) == 1 else str(len(stack))) + stack[-1]
                stack = [string]
            tempS = tempS[number:]
        compression += ('' if len(stack) == 1 else str(len(stack))) + stack[-1] + tempS
        answer = answer if answer < len(compression) else len(compression)
    return answer
