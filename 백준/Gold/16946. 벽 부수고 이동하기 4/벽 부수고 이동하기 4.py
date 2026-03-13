import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

maps = []
dir = {}
visited = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    maps.append(input().rstrip())

def s(i, j, checker):
    q = deque()
    q.append((i, j))
    visited[i][j] = checker
    temp = 1

    while q:
        x, y = q.popleft()

        if y+1 < m and maps[x][y+1] == '0' and visited[x][y+1] == 0:
            visited[x][y+1] = checker
            q.append((x, y+1))
            temp += 1

        if y-1 >= 0 and maps[x][y-1] == '0' and visited[x][y-1] == 0:
            visited[x][y-1] = checker
            q.append((x, y-1))
            temp += 1

        if x+1 < n and maps[x+1][y] == '0' and visited[x+1][y] == 0:
            visited[x+1][y] = checker
            q.append((x+1, y))
            temp += 1

        if x-1 >= 0 and maps[x-1][y] == '0' and visited[x-1][y] == 0:
            visited[x-1][y] = checker
            q.append((x-1, y))
            temp += 1

    return temp

c = 1

for i in range(n):
    for j in range(m):
        if maps[i][j] == '0' and visited[i][j] == 0:
            visited[i][j] = c
            check = s(i, j, c)
            dir[c] = dir.get(c, 0) + check
            c += 1

for i in range(n):
    for j in range(m):
        if maps[i][j] == '1':
            ret = 0
            t = []
            if j+1 < m and maps[i][j+1] == '0':
                if visited[i][j+1] in t:
                    0
                else:
                    t.append(visited[i][j+1])
            
            if j-1 >= 0 and maps[i][j-1] == '0':
                if visited[i][j-1] in t:
                    0
                else:
                    t.append(visited[i][j-1])
            
            if i+1 < n and maps[i+1][j] == '0':
                if visited[i+1][j] in t:
                    0
                else:
                    t.append(visited[i+1][j])
            
            if i-1 >= 0 and maps[i-1][j] == '0':
                if visited[i-1][j] in t:
                    0
                else:
                    t.append(visited[i-1][j])
            for l in t:
                ret += dir.get(l)
            ret += 1
            print(ret%10, end="")
        else:
            print(0, end="")
    print()
