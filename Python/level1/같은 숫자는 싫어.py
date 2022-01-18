def solution(arr):
    answer = [arr[0]]
    for index,word in enumerate(arr):
        if answer[-1] != word:
            answer.append(word)
        prevWord = word
    return answer
