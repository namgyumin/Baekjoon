import sys

n = int(sys.stdin.readline())

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(n):
    temp = list(map(int, sys.stdin.readline().split()))
    for j in range(len(temp)):
        dp[i][j] = temp[j]

for i in range(1, n):
    for j in range(i+1):
        if(j == 0):
            dp[i][j] = dp[i-1][j] + dp[i][j]
        elif(j == i):
            dp[i][j] = dp[i-1][j-1] + dp[i][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + dp[i][j]

ret = 0
for i in range(n):
    ret = max(dp[n-1][i], ret)
print(ret)