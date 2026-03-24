import math as m
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
byte = list(map(int, input().split()))
value = list(map(int, input().split()))

total = 0
for i in value:
    total += i

dp = [0 for _ in range(total+1)]

for i in range(n):
    for j in range(total, -1, -1):
        if j - value[i] >= 0:
            dp[j] = max(dp[j], dp[j-value[i]] + byte[i])

for i in range(0, total+1):
    if dp[i] >= m:
        print(i)
        break
