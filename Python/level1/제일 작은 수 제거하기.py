def solution(arr):
    if len(arr) != 1:
        arr.remove(sorted(arr)[0]) if len(arr) != 1 else [-1]
    else:
        arr = [-1]
    return arr

# def rm_small(mylist):
#   return [i for i in mylist if i > min(mylist)]
