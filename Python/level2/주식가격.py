def solution(prices):
    answer = [0] * len(prices)
    stack = [[0,prices[0]]]
    for index in range(1, len(prices)):
        while stack and stack[-1][1] > prices[index]:
            priceIndex = stack.pop()[0]
            answer[priceIndex] = index - priceIndex
        stack.append([index,prices[index]])      
    
    for index, price in stack:
        answer[index] = len(prices) - 1 - index
    return answer
