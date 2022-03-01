def solution(n, words):
    answer = []
    word = {words[0]:1}
    for count in range(1,len(words)):
        if words[count] in word or words[count - 1][-1] != words[count][0]:
            answer = [count % n + 1, count // n + 1]
            break
        word[words[count]] = 1
        count += 1
    
    if not answer:
        answer = [0,0]

    return answer
