import sys
from itertools import combinations

n = int(sys.stdin.readline())

sArr = []
bArr = []

for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    sArr.append(a)
    bArr.append(b)

minin = 10**18

for i in range(1, n+1):
    for comb in combinations(range(0, n), i):
        shob = 1
        bhob = 0
        for j in comb:
            shob *= sArr[j]
            bhob += bArr[j]
        minin = min(minin, abs(shob-bhob))

print(minin)