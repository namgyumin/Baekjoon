import sys

goal = int(sys.stdin.readline())
now = 100
n = int(sys.stdin.readline())
arr = []
if n != 0:
    arr = list(sys.stdin.readline().replace(' ', '').strip())

minin = 500000
minin = min(minin, abs(goal - now))
temp = 0
for i in range(0, 1000000):
    temp = list(str(i))
    flag = 0
    for j in temp:
        if j in arr:
            flag = 1
    if flag == 0:
        minin = min(minin, abs(goal - i) + len(temp))

print(minin)