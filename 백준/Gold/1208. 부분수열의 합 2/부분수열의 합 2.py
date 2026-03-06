import sys
from itertools import combinations

input = sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))
ret = 0
left = []
right = []
leftdp = {}
rightdp = {}
rightdp[0] = rightdp.get(0, 1)
leftdp[0] = leftdp.get(0, 1)

for i in range(n//2+1):
    left.append(arr[i])
for i in range(1, len(left)+1):
    for comb in combinations(left, i):
        temp = 0
        for j in comb:
            temp += j
        leftdp[temp] = leftdp.get(temp, 0) + 1

for i in range(n//2+1, n):
    right.append(arr[i])

for i in range(1, len(right)+1):
    for comb in combinations(right, i):
        temp = 0
        for j in comb:
            temp += j
        rightdp[temp] = rightdp.get(temp, 0) + 1

for i in leftdp.items():
    temp = s - i[0]
    mutiply = i[1]
    if temp in rightdp:
        ret += rightdp.get(temp) * mutiply

if s == 0:
    ret -= 1
print(ret)