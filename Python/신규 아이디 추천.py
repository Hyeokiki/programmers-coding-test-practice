def solution(new_id):
    answer = pipe([stepOne,stepTwo,stepThree,stepFour,stepFive,stepSix,stepSeven],new_id)
    return answer

def stepOne(new_id):
    return new_id.lower()

def stepTwo(new_id):
    stepTwoID = ''
    exceptWords = ['-','_','.']
    for word in new_id:
        if word.isalpha() or word.isdigit() or word in exceptWords:
            stepTwoID = stepTwoID + word
    return stepTwoID

def stepThree(new_id):
    stepThreeID = ''
    prevWord = ''
    for word in new_id:
        if not (prevWord == '.' and word == '.'):
            stepThreeID = stepThreeID + word
        prevWord = word
    return stepThreeID

def stepFour(new_id):
    stepFourID = new_id
    if new_id[0] == '.':
        stepFourID = stepFourID[1:]
    if new_id[-1] == '.':
        stepFourID = stepFourID[:-1]
    return stepFourID

def stepFive(new_id):
    if not new_id:
        return 'a'
    return new_id

def stepSix(new_id):
    stepSixID = new_id
    if len(new_id) >= 16:
        stepSixID = stepSixID[:15]
        if stepSixID[-1] == '.':
            stepSixID = stepSixID[:-1]
    return stepSixID
    
def stepSeven(new_id):
    stepSevenID = new_id
    idLength = len(stepSevenID)
    if idLength <=2:
        stepSevenID = stepSevenID + stepSevenID[-1]*(3-idLength)
    return stepSevenID
    
def pipe(functions,new_id):
    id = new_id
    for function in functions:
        id = function(id)
    return id
