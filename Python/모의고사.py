def solution(answers):
    answer = []
    scores = [0,0,0]
    first = [1,2,3,4,5]
    second = [2,1,2,3,2,4,2,5]
    third = [3,3,1,1,2,2,4,4,5,5]
    for index in range(len(answers)):
        if answers[index] == first[index % len(first)]:
            scores[0] += 1
        if answers[index] == second[index % len(second)]:
            scores[1] += 1
        if answers[index] == third[index % len(third)]:
            scores[2] += 1
    maxScore = sorted(scores)[-1]
    for index,score in enumerate(scores):
        if score == maxScore:
            answer.append(index+1)
    return answer
