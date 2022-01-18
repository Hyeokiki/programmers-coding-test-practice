def solution(strings, n):
    answer = []
    letters = []
    for string in strings:
        letters.append(string[n])
    letters = sorted(list(set(letters)))
    for letter in letters:
        for string in sorted(strings):
            if string[n] == letter:
                answer.append(string)
    return answer

# sorted(array, key) key,
# lambda 매개변수 : 표현식
# def solution(strings, n):
#     return sorted(strings, key=lambda strings:strings[n])
