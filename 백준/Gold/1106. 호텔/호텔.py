import sys

input = sys.stdin.readline

c, n = map(int, input().split())

cost = []
people = []

pmax = 0

for i in range(n):
    co, p = map(int, input().split())
    pmax = max(p, pmax)
    cost.append(co)
    people.append(p)

nm = c+pmax

dp = [10**18 for _ in range(nm+1)]
dp[0] = 0

for i in range(nm+1):
    for j in range(n):
        if people[j] <= i:
            dp[i] = min(dp[i], dp[i-people[j]] + cost[j])
    if i > c:
        dp[c] = min(dp[c], dp[i])

print(dp[c])
