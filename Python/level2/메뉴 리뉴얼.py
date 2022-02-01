from itertools import combinations
from wsgiref.handlers import format_date_time

def solution(orders, course):
    answer = []
    setMenu = {}
    maxMenu = [[] for i in range(len(course))]
    maxCount = [1] * len(course)
    for order in orders:
        orderList = list(order)
        for index, count in enumerate(course):
            for food in combinations(orderList, count):
                foodString = ''.join(sorted(list(food)))
                if foodString in setMenu.keys():
                    setMenu[foodString] += 1
                else:
                    setMenu[foodString] = 1
                    
                if maxCount[index] < setMenu[foodString]:
                    maxCount[index] = setMenu[foodString]
                    maxMenu[index] = [foodString]
                if maxCount[index] == setMenu[foodString] and maxCount[index] != 1:
                    if foodString not in maxMenu[index]:
                        maxMenu[index].append(foodString)
    for menus in maxMenu:
        for menu in menus:
            answer.append(menu)
    return sorted(answer)

# 조합
# from itertools import combinations

# combinations([1,2,3,4], 2)
# (1, 2) (1, 3) (1, 4) (2 ,3) (2, 4) (3, 4)
