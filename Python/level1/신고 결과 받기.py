def solution(id_list, report, k):
    answer = [0] * len(id_list)
    result = {}
    for string in report:
        [user,reportedUser] = string.split(' ')
        if reportedUser in result.keys():
            result[reportedUser] = list(set(result[reportedUser] + [user]))
        else:
            result[reportedUser] = [user]
    for reportedUser, users in result.items():
        if len(users) >= k:
            for user in users:
                answer[id_list.index(user)] += 1
    return answer
