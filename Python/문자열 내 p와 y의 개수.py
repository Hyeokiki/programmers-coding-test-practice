def solution(s):
    isP = 0
    for letter in s.lower():
        if letter == 'p':
            isP += 1
        if letter == 'y':
            isP -= 1
    return isP == 0

# def solution(s):
#     return s.lower().count('p') == s.lower().count('y')
