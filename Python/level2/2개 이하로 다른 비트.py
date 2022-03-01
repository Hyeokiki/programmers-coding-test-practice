def solution(numbers):
    answer = []
    for number in numbers:
        binary = bin(int(number))[2:]
        if int(number) % 2 == 0:
            answer.append(int(number) + 1)
        else:
            for index, binaryNumber in enumerate(reversed(binary)):
                if binaryNumber == '0':
                    answer.append(number + 2 ** (index - 1))
                    break
            else:
                answer.append(number + 2 ** (len(binary)-1))
    return answer
