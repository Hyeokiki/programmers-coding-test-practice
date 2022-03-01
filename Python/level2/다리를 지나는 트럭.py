def solution(bridge_length, weight, truck_weights):
    answer = 0
    queue = []
    index = 0
    total = 0
    end = 0
    while end != len(truck_weights):
        if index < len(truck_weights) and total + truck_weights[index] <= weight and len(queue) < bridge_length:
            queue.append([0,truck_weights[index]])
            total += truck_weights[index]
            index += 1
        for i in range(len(queue)):
            queue[i][0] += 1
        if queue[0][0] == bridge_length:
            temp = queue.pop(0)
            total -= temp[1]
            end += 1
        answer += 1
        
        
    return answer + 1


# 다른 풀이
# def solution(bridge_length, weight, truck_weights):
#     answer = 0
#     queue = [0] * bridge_length
#     index = 0
#     while queue:
#         queue.pop(0)
#         answer += 1
#         if index < len(truck_weights):
#             if sum(queue) + truck_weights[index] > weight:
#                 queue.append(0)
#             else:
#                 queue.append(truck_weights[index])
#                 index += 1
            
        
#     return answer
