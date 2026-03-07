import sys

input = sys.stdin.readline

n = int(input())

aList = []
bList = []
cList = []
dList = []

## 목표 : ab cd 로 나눠서 저번에 햇던 그 중간에서 만나기 그거 

abDic = {}
cdDic = {}

for i in range(n):
    a,b,c,d = map(int, input().split())
    aList.append(a)
    bList.append(b)
    cList.append(c)
    dList.append(d)

ret = 0

for i in range(n):
    for j in range(n):
        temp = aList[i] + bList[j]
        abDic[temp] = abDic.get(temp, 0) + 1

for i in range(n):
    for j in range(n):
        temp = cList[i] + dList[j]
        if -temp in abDic:
            ret += abDic.get(-temp)
print(ret)