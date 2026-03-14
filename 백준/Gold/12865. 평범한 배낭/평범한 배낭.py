import sys

input = sys.stdin.readline

n, k = map(int, input().split())

class backpack:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value

lis = []

for i in range(n):
    w, v = map(int, input().split())
    lis.append(backpack(w, v))

dp = [0 for _ in range(k+1)]

for j in range(n):
    temp = lis[j]
    for i in range(k, temp.weight-1, -1):
        dp[i] = max(dp[i], dp[i-temp.weight] + temp.value)

print(dp[k])