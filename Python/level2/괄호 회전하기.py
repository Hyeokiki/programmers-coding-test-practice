def solution(s):
    answer = 0
    for shuffleIndex in range(len(s)):
        copy = s[shuffleIndex:] + s[:shuffleIndex]
        stack = []
        for index in range(len(copy)):
            if not stack:
                stack.append(copy[index])
            else:
                poppedString = stack.pop()
                prevBracket = checkBracket(poppedString)
                nowBracket = checkBracket(copy[index])
                if not (prevBracket < 0 and prevBracket + nowBracket == 0):
                    stack = stack + [poppedString, copy[index]]
        if not stack:
            answer += 1
    return answer

def checkBracket(bracket):
    if bracket == '[':
        return -1
    elif bracket == '{':
        return -2
    elif bracket == '(':
        return -3
    elif bracket == ')':
        return 3
    if bracket == '}':
        return 2
    elif bracket == ']':
        return 1
