import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

dp = [1 for _ in range(n)]

for i in range(n):
    for j in range(i):
        if(arr[j] < arr[i]):
            dp[i] = max(dp[j]+1, dp[i])

temp = 0

for i in range(n):
    temp = max(temp, dp[i])

print(temp)