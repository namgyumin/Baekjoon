import sys
sys.setrecursionlimit(20000)
t = int(sys.stdin.readline())

def mainFunction():
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    goal = int(sys.stdin.readline())
    
    dp = [0]*(goal+1)
    dp[0] = 1

    for i in arr:
        for j in range(i, goal+1):
            dp[j] += dp[j-i]

    print(dp[goal])
    
for _ in range(t):
    mainFunction()
    