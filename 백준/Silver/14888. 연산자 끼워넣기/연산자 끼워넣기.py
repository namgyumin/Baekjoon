import sys

n = int(sys.stdin.readline())

numArr = list(map(int, sys.stdin.readline().split()))
cal = list(map(int, sys.stdin.readline().split()))

def applyToCalculator(firstValue, secondValue, idxValue):
    if idxValue == 0:
        return firstValue + secondValue
    if idxValue == 1:
        return firstValue - secondValue
    if idxValue == 2:
        return firstValue * secondValue
    if idxValue == 3:
        return int(firstValue / secondValue)

mx = -10**18
mi = 10**18

def dfs(step, value):
    global mx
    global mi
    if step == n:
        mx = max(mx, value)
        mi = min(mi, value)
        return
    for i in range(4):
        if cal[i] == 0:
            continue
        cal[i] -= 1
        dfs(step+1, applyToCalculator(value, numArr[step], i))
        cal[i] += 1

dfs(1, numArr[0])

print(mx)
print(mi)