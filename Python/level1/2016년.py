calender = [31,29,31,30,31,30,31,31,30,31,30,31]
day = ['THU','FRI','SAT','SUN','MON','TUE','WED']

def solution(a, b):
    count = 0
    for month in range(a-1):
        count += calender[month]
    count += b
    return day[count % 7]
