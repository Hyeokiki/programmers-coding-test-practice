import math

def solution(nums):
    answer = 0
    for first in range(len(nums)-2):
        for second in range(first+1,len(nums)-1):
            for third in range(second+1,len(nums)):
                sum = nums[first] + nums[second] + nums[third]
                for index in range(2, int(math.sqrt(sum)) + 1):
                    if sum % index == 0:
                        break
                else:
                    answer += 1
    return answer
