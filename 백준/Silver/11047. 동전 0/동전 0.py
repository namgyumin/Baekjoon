import sys

n, cost = map(int, sys.stdin.readline().split())

arr = []

for i in range(n):
    t = int(sys.stdin.readline())
    arr.append(t)

arr.sort(reverse=True)


ret = 0

for i in arr:
    if i <= cost:
        while i <= cost:
            ret += 1
            cost -= i

print(ret)