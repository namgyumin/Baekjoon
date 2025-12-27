MOD = 1000000009

T = int(input())

arr = [0 for _ in range(1000004)]
arr[1] = 1
arr[2] = 1
arr[3] = 1

for i in range(1, 1000001):
    temp = arr[i]
    arr[i+1] = (arr[i+1] + temp) % MOD
    arr[i+2] = (arr[i+2] + temp) % MOD
    arr[i+3] = (arr[i+3] + temp) % MOD

for _ in range(T):
    n = int(input())
    print(arr[n])
