def solution(s):
    answer = ''
    count = 0
    for index, string in enumerate(s):
        if string == ' ':
            answer += ' '
            count = 0
            continue
        answer += string.upper() if count % 2 == 0 else string.lower()
        count += 1
    return answer
