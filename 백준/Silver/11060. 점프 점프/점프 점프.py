import sys

n = int(sys.stdin.readline())

arr = []

arr = list(map(int, sys.stdin.readline().split()))

dp = [-1 for _ in range(n)]


def function(dp, arr, step, value):
    if step >= n:
        return
    if dp[step] != -1 and value>= dp[step]:
        return
    dp[step] = value
    
    if step == n-1:
        return
    
    for i in range(step + 1, step + arr[step] + 1):
        if(i >= n):
            break;
        function(dp, arr, i, value+1)

function(dp, arr, 0, 0)

print(dp[n-1])