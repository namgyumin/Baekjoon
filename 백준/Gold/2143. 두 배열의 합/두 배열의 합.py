import sys

input = sys.stdin.readline

t = int(input())

aLen = int(input())
aList = list(map(int, input().split()))
bLen = int(input())
bList = list(map(int, input().split()))

aDic = {}
bDic = {}

aDp = [0 for _ in range(aLen)]
bDp = [0 for _ in range(bLen)]

for i in range(aLen):
    for j in range(i+1):
        aDp[j] += aList[i]
        aDic[aDp[j]] = aDic.get(aDp[j], 0) + 1

for i in range(bLen):
    for j in range(i+1):
        bDp[j] += bList[i]
        bDic[bDp[j]] = bDic.get(bDp[j], 0) + 1

ret = 0

for i in aDic.items():
    temp = t - i[0]
    muti = i[1]
    if temp in bDic:
        ret += bDic.get(temp) * muti

print(ret)