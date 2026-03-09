import sys
input = sys.stdin.readline

n, goal = map(int, input().split())

arr = list(map(int, input().split()))

left = right = 0
total = arr[0]
minin = 1000000
while True:
    if left == right:
        total = arr[left]
        if total >= goal:
            minin = 1
        right += 1
        if right >= n:
            break
        else:
            total += arr[right]
    if total >= goal:
        minin = min(minin, right - left + 1)
        total -= arr[left]
        left += 1
        if left >= n:
            break
    if total < goal:
        if right + 1 >= n:
            break
        else:
            right += 1
            total += arr[right]

if minin == 1000000:
    print(0)
else:
    print(minin)