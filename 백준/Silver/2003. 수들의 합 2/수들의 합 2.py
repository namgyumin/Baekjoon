import sys

input = sys.stdin.readline

n, goal = map(int, input().split())

left = right = total = count =  0

arr = list(map(int, input().split()))

while True:
    if total == goal:
        count += 1
    if right == n:
        if total < goal or left == n:
            break
        else:
            total -= arr[left]
            left += 1
    else:
        if total <= goal:
            total += arr[right]
            right += 1
        elif total > goal:
            total -= arr[left]
            left += 1

print(count)