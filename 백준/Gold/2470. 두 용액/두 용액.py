import sys
input = sys.stdin.readline

n = int(input())
arr = sorted(map(int, input().split()))

left = 0
right = n - 1

minin = 10**18
lefty = arr[left]
righty = arr[right]

while left < right:
    temp = arr[left] + arr[right]

    if abs(temp) < minin:
        minin = abs(temp)
        lefty = arr[left]
        righty = arr[right]

    if temp > 0:
        right -= 1
    elif temp < 0:
        left += 1
    else:
        break

print(lefty, righty)