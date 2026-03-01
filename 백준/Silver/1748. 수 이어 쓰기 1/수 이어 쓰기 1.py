import sys

n = int(sys.stdin.readline())
lis = [0, 9, 99, 999, 9999, 99999, 999999, 9999999,99999999,999999999]
ans = 0
for i in range(1, len(lis)): 
    if n <= lis[i-1]:
        break  
    end = min(n, lis[i])
    cnt = end - lis[i-1]
    ans += i * cnt
print(ans)