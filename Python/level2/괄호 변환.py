def solution(p):
    if not p:
        return p
    
    flag = True
    count = 0
    index = 0
    for i in range(len(p)):
        count += -1 if p[i] == '(' else 1
        if count > 0:
            flag = False
        if count == 0:
            [u, v] = [p[:i + 1], p[i + 1:]]
            if flag:
                return u + solution(v)
            answer = '(' + solution(v) + ')'
            answer += ''.join(['(' if s == ')' else ')' for s in u[1:-1]])
            return answer


# 첫 풀이
# def solution(p):
#     if not p:
#         return p
    
#     count = 0
#     index = 0
#     for i in range(len(p)):
#         count += -1 if p[i] == '(' else 1
#         if count == 0:
#             index = i
#             break
#     [u, v] = [p[:index + 1], p[index + 1:]]
    
#     if isRight(u):
#         return u + solution(v)
#     answer = '(' + solution(v) + ')'
#     answer += ''.join(['(' if s == ')' else ')' for s in u[1:-1]])
#     return answer

# def isRight(string):
#     stack = [string[0]]
#     for i in range(1,len(string)):
#         if len(stack) == 0:
#             stack.append(string[i])
#         elif stack[-1] == '(' and string[i] == ')':
#             stack.pop()
#         else:
#             stack.append(string[i])
#     return True if len(stack) == 0 else False
