def solution(n):
    numbers = [1,1] + [0] * (n - 1)
    for index in range(2, n+1):
        if index == 0 or index == 1:
            continue
        if numbers[index] == 0:
            for number in range(index*2,n+1,index):
                numbers[number] = 1
    return len([index for number in numbers if number == 0])

# def solution(n):
#     num=set(range(2,n+1))

#     for i in range(2,n+1):
#         if i in num:
#             num-=set(range(2*i,n+1,i))
#     return len(num)
# set은 차집합이 가능하다
