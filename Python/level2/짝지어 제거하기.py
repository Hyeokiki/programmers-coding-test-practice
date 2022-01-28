def solution(s):
    stack = []
    for string in s:
        if len(stack) == 0:
            stack.append(string)
        else:
            prevString = stack.pop()
            if prevString != string:
                stack += [prevString, string]
    return 1 if len(stack) == 0 else 0
