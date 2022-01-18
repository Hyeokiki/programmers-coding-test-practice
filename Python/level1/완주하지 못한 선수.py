def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    for index in range(len(completion)):
        if participant[index] != completion[index]:
            answer = participant[index]
            break
    else:
        answer = participant[-1]
    return answer
