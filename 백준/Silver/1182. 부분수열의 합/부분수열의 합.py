import sys
from itertools import combinations

input = sys.stdin.readline

n, s = map(int, input().split())
arr = list(map(int, input().split()))

ret = 0

for i in range(1, n+1):
    for comb in combinations(arr, i):
        temp = 0
        for j in comb:
            temp += j
        if temp == s:
            ret +=1 

print(ret)