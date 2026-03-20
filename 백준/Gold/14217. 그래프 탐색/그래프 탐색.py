import sys
from collections import deque

input = sys.stdin.readline

city, num = map(int, input().split())

lis = [set() for _ in range(city)]

for _ in range(num):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    lis[a].add(b)
    lis[b].add(a)

n = int(input())

def function():
    global city
    x, y, z = map(int, input().split())
    if x == 2:
        lis[y-1].discard(z-1)
        lis[z-1].discard(y-1)
    else:
        lis[z-1].add(y-1)
        lis[y-1].add(z-1)
    visited = [-1 for _ in range(city)]
    q = deque()
    visited[0] = 0
    q.append(0)
    while q:
        temp = q.popleft()
        for i in lis[temp]:
            if visited[i] == -1:
                visited[i] = visited[temp]+1
                q.append(i)
    for i in visited:
        print(i, end = " ")
    print()

for i in range(n):
    function()