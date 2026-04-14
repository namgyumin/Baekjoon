import sys

temp = list(sys.stdin.readline().rstrip())

arr = []

for i in temp:
    arr.append(int(i))

arr.sort(reverse=True)

for i in arr:
    print(i,end="")