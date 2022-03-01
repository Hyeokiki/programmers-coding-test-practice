def solution(citations):
    citations.sort()
    length = len(citations)
    for index in range(length):
        if citations[index] >= length - index:
            return length - index
    return 0



# 다른 풀이
# def solution(citations):
#     answer = 0
#     citations.sort(reverse=True)
#     for index, number in enumerate(citations):
#         temp = min(index + 1, number)
#         if answer < temp:
#             answer = temp
#     return answer
