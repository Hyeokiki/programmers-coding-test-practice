def solution(word):
    answer = len(word)
    order = ['A','E','I','O','U']
    word = word if len(word) == 5 else word+'0'*(5-len(word))
    temp = 0
    for index,letter in enumerate(word[::-1]):
        temp = 5*temp + 1
        if letter == '0':continue
        answer += temp * order.index(letter)
    return answer
