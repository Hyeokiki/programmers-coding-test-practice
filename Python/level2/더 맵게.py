import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while scoville[0] < K and len(scoville) > 1:
        heapq.heappush(scoville, heapq.heappop(scoville) + heapq.heappop(scoville) * 2)
        answer += 1
    if scoville[0] < K and len(scoville) == 1:
        answer = -1
    return answer


# import heapq

# 최소 힙 생성, push
# heap_list = []
# heapq.heappush(heap_list, 4)
# heapq.heappush(heap_list, 1)
# heapq.heappush(heap_list, 7)

# pop
# heapq.heappop(heap_list)

# pop하지 않고 최솟값 얻기
# print(heap_list[0])

# 기존 리스트를 힙으로 변환
# a_list = [4, 1, 7, 3, 8, 5]
# heapq.heapify(a_list)
