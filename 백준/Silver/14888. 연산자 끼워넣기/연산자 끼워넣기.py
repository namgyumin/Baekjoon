import sys

n = int(sys.stdin.readline())

numArr =  list(map(int, sys.stdin.readline().split()))
cal = list(map(int, sys.stdin.readline().split()))

def function(plus, minus, mutiply, divide, numArr, cal, step, value, maxim, minum, n):
    if step == 0:
        return function(plus, minus, mutiply, divide, numArr, cal, step+1, numArr[0], maxim, minum, n)
    if n == step:
        return value, value
    else:
        if cal[0] > plus:
            ma, mi = function(plus+1, minus, mutiply, divide, numArr, cal, step+1, value+numArr[step], maxim, minum, n)
            maxim = max(maxim, ma)
            minum = min(minum, mi)
        if cal[1] > minus:
            ma, mi = function(plus, minus+1, mutiply, divide, numArr, cal, step+1, value-numArr[step], maxim, minum, n)
            maxim = max(maxim, ma)
            minum = min(minum, mi)
        if cal[2] > mutiply:
            ma, mi = function(plus, minus, mutiply+1, divide, numArr, cal, step+1, value*numArr[step], maxim, minum, n)
            maxim = max(maxim, ma)
            minum = min(minum, mi)
        if cal[3] > divide:
            ma, mi = function(plus, minus, mutiply, divide+1, numArr, cal, step+1, int(value/numArr[step]), maxim, minum, n)
            maxim = max(maxim, ma)
            minum = min(minum, mi)
        return maxim, minum

ma, mi = function(0, 0, 0, 0, numArr, cal, 0, 0, -(10**18), 10**18, n)
print(ma)
print(mi)