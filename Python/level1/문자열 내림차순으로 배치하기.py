def solution(s):
    low = []
    high = []
    for letter in s:
        low.append(letter) if letter.islower() else high.append(letter)
    return ''.join(sorted(low, reverse = True)) + ''.join(sorted(high, reverse = True))

# def solution(s):
#     return ''.join(sorted(s), reverse = True)
# string을 정렬하면 앞이 대문자 뒤가 소문자로 정렬된다.
