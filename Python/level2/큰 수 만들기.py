def solution(number, k):
    stack = []
    for n in number:
        while k > 0 and stack and stack[-1] < n:
            stack.pop()
            k -= 1
        stack.append(n)
    return ''.join(stack[:len(number) - k])


def solution(number, k):
    return greedy(number, k, 0, '')

def greedy(number, k, index, answer):
    if k == 0:
        answer += number[index:]
        return answer
    if len(number) - index == k:
        return answer
    remove = greedy(number, k - 1, index + 1, answer)
    alive = greedy(number, k, index + 1, answer + number[index])
    return max(alive,remove)
