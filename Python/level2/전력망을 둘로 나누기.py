import copy

def solution(n, wires):
    answer = n
    tree = {}
    for wire in wires:
        if wire[0] not in tree.keys():
            tree[wire[0]] = []
        if wire[1] not in tree.keys():
            tree[wire[1]] = []
        tree[wire[0]].append(wire[1])
        tree[wire[1]].append(wire[0])

    for wire in wires:
        newTree = copy.deepcopy(tree)
        newTree[wire[0]].remove(wire[1])
        newTree[wire[1]].remove(wire[0])
        tempList = [wire[0]]
        wireList = []
        count = 0
        
        while tempList:
            temp = tempList.pop()
             
            if temp in newTree.keys():
                tempList += newTree[temp]
                del newTree[temp]
                
            if temp not in wireList:
                wireList.append(temp)
                count += 1
                
        if answer > abs(n-count * 2):
            answer = abs(n-count * 2)
    return answer
