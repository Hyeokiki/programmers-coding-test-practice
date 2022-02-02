import re

def solution(expression):
    answer = []
    operations = re.compile('[/+-/*]').findall(expression)
    numbers = re.compile('\d+').findall(expression)
    expressionList = [numbers[0]]
    for index in range(len(operations)):
        expressionList += [operations[index],numbers[index + 1]]
    orders = []
    dfs(set(operations),'',0,orders)
    for order in orders:
        copy = expressionList[:]
        for operation in order:
            while operation in copy:
                index = copy.index(operation)
                copy.insert(index - 1,eval(str(copy[index-1])+copy[index]+str(copy[index+1])))
                del copy[index:index + 3]
        answer.append(abs(int(copy[0])))
    return max(answer)

def dfs(operations,string,index,order):
    if index == len(operations):
        order.append(string)
        return
    for operation in operations:
        if operation not in string:
            dfs(operations,string+operation,index+1,order)

# eval('100+200') = 300
