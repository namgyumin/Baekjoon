import sys

n, l = map(int, sys.stdin.readline().split())

while(True):
    if l > 100:
        print(-1)
        break
    temp = int(n/l - (int((l+1)/2) - 1))
    if temp < 0 :
        print("-1")
        break;
    total = 0
    for i in range(temp, temp+l):
        total += i
    if total == n:
        for i in range(temp, temp+l):
            print(i)
        break;
    else:
        l += 1