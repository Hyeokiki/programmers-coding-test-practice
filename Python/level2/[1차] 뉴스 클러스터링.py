def solution(str1, str2):
    answer = 0
    array1 = [(str1[i]+str1[i+1]).lower() for i in range(len(str1) - 1) if str1[i].isalpha() and str1[i+1].isalpha()]
    array2 = [(str2[i]+str2[i+1]).lower() for i in range(len(str2) - 1) if str2[i].isalpha() and str2[i+1].isalpha()]
    union = set(array1) | set(array2)
    intersection = set(array1) & set(array2)
    
    if not len(union):
        answer = 1
    else:
        unionCount = sum([max(array1.count(u), array2.count(u)) for u in union])
        intersectionCount = sum([min(array1.count(i), array2.count(i)) for i in intersection])
        answer = intersectionCount / unionCount
    return int(answer * 65536)


# 첫 제출
# 리스트의 count메소드를 활용하자
# def solution(str1, str2):
#     str1, str2 = str1.lower(), str2.lower()
#     dict1 = {}
#     dict2 = {}
#     for index in range(len(str1) - 1):
#         key = str1[index] + str1[index + 1]
#         if not key.isalpha():
#             continue
#         if key in dict1.keys():
#             dict1[key] += 1
#         else:
#             dict1[key] = 1
            
#     unionDict = dict1.copy()
#     intersectionDict = {}
    
#     for index in range(len(str2) - 1):
#         key = str2[index] + str2[index + 1]
#         if not key.isalpha():
#             continue
#         if key in dict2.keys():
#             dict2[key] += 1
#         else:
#             dict2[key] = 1
#         if key in unionDict.keys():
#             if unionDict[key] < dict2[key]:
#                 unionDict[key] = dict2[key]
#             else:
#                 intersectionDict[key] = dict2[key]
#         else:
#             unionDict[key] = 1
#     if not len(intersectionDict) and not len(unionDict):
#         answer = 1
#     else:
#         answer = sum([number for number in intersectionDict.values()]) / sum([number for number in unionDict.values()])
#     return int(answer * 65536)
