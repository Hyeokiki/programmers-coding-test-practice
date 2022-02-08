def solution(priorities, location):
    answer = 1
    sortedPriorities = sorted(priorities)
    
    while True:
        if priorities[0] < sortedPriorities[-1]:
            priorities = priorities[1:] + [priorities[0]]
            location = len(priorities) - 1 if location == 0 else location - 1
        else:
            if location == 0:
                break
            else:
                location -= 1
                priorities.pop(0)
                sortedPriorities.pop()
                answer += 1
    return answer
