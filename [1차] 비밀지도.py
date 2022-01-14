def solution(n, arr1, arr2):
    numbers = [arr1[index] | arr2[index] for index in range(n)]
    map = []
    for i in range(n):
        wall = ''
        while numbers[i] != 0:
            wall = ('#' if numbers[i] % 2 == 1 else ' ') + wall
            numbers[i] = numbers[i] // 2
        map.append(wall if len(wall) == n else ' ' * (n - len(wall)) + wall)
    return map

# str.zfill(width) width 길이만큼 앞에 0이 생김
# str.rjust(width,[fillChar]) width 길이만큼 앞에 fillChar가 생김
