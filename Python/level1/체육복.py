def solution(n, lost, reserve):
    noClothes = set(lost) - set(reserve)
    extraClothes = set(reserve) - set(lost)
    for number in extraClothes:
        if number - 1 in noClothes:
            noClothes.remove(number - 1)
        elif number + 1 in noClothes:
            noClothes.remove(number + 1)
    return n - len(noClothes)
