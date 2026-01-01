dp = [0 for _ in range(1001)]

dp[0] = dp[1] = 1

for i in range(2, 1001):
    temp = 1
    
    value = [0 for _ in range(1001)]
    
    while(True):
        if i-(temp*2) < 0:
            break
        cand = (2*dp[i-temp])-dp[i-(temp*2)]
        if 1 <= cand <= 1000:
            value[cand] = 1
        temp += 1
    
    for j in range(1, 1001):
        if value[j] == 0:
            dp[i] = j
            break

ret = int(input())

print(dp[ret])