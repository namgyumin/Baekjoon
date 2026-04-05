import sys
from bisect import bisect_left

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

stack = []

for x in arr:
    if not stack or stack[-1] < x:
        stack.append(x)
    else:
        idx = bisect_left(stack, x)
        stack[idx] = x

print(len(stack))