import sys

input = sys.stdin.readline

n, c = map(int, input().split())

arr = []
for i in range(n):
    t = int(input())
    arr.append(t)

arr = sorted(arr)


small = 1
big = arr[n-1]

while small <= big:
    mid = (small + big) // 2
    count = 0
    temp = arr[0]
    for i in range(1, n):
        if arr[i] - temp >= mid:
            count += 1
            temp = arr[i]
    if count >= c-1:
        small = mid + 1
    else:
        big = mid - 1

print(big)