import sys

def function(number):
    if number <= 0:
        return 0
    if number <= 9:
        return number * (number + 1) // 2
    
    a = len(str(number))
    temp = 1
    for i in range(a-1):
        temp *= 10

    msd = number // temp
    rest = number % temp

    return (
        msd * function(temp - 1)
        + (msd * (msd - 1) // 2) * temp
        + msd * (rest + 1)
        + function(rest)
    )

a, b = map(int, sys.stdin.readline().split())
print(function(b) - function(a-1))