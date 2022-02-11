import itertools

def solution(numbers):
    answer = set()
    for index in range(1, len(numbers) + 1):
        for permutation in itertools.permutations(list(numbers), index):
            number = int(''.join(permutation))
            for div in range(2,int(number ** (1/2)) + 1):
                if number % div == 0:
                    break
            else:
                if number != 1 and number != 0:
                    answer.add(number)
    return len(answer)
