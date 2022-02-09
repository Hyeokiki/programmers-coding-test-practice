def solution(record):
    answers = []
    usernames = {}
    for string in record:
        splitedString = string.split(' ')
        if splitedString[0] == 'Change':
            usernames[splitedString[1]] = splitedString[2]
        else:
            if splitedString[0] == 'Enter':
                usernames[splitedString[1]] = splitedString[2]
            answers.append([splitedString[1],'님이 ' + ('들어왔습니다.' if splitedString[0] == 'Enter' else '나갔습니다.')])
            
    return [usernames[answer[0]]+answer[1] for answer in answers]
