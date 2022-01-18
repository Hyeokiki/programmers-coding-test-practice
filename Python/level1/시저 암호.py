def solution(s, n):
    answer = ''
    for string in s:
        newOrd = ord(string) + n
        if ord(string) <= ord('Z') and newOrd > ord('Z'):
            newOrd = ord('A') + newOrd - ord('Z') - 1
        if ord(string) >= ord('a') and newOrd > ord('z'):
            newOrd = ord('a') + newOrd - ord('z') - 1
        answer += chr(newOrd) if string != ' ' else ' '
    return answer
