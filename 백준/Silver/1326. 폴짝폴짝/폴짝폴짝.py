import sys

## 입력 기본 세팅
input = sys.stdin.readline
n = int(input())

m = list(map(int, input().split()))

visited = [-1 for _ in range(n)]
start, goal = map(int, input().split())
start -= 1
goal -= 1

## goal 이상으로는 갈 수 없기 때문에 기준 bfs 포문을 goal로 두자

q = []
whereQ = 0
visited[start] = 0
q.append(start)


while len(q) != whereQ:
    temp = q[whereQ]
    forIter = temp + m[temp]
    whereQ += 1
    vIter = visited[temp]
    while forIter < n:
        visited[forIter]
        if visited[forIter] == -1 or  visited[forIter] > vIter + 1:
            q.append(forIter)
            visited[forIter] = vIter + 1
        forIter += m[temp]
    forIter = temp - m[temp]
    while forIter >= 0:
        visited[forIter]
        if visited[forIter] == -1 or  visited[forIter] > vIter + 1:
            q.append(forIter)
            visited[forIter] = vIter + 1
        forIter -= m[temp]

print(visited[goal])