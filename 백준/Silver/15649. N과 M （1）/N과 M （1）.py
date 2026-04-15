from itertools import combinations

n, m = map(int, input().split())
arr = [0 for i in range(m)]
def fun(now, step):
    if step == m:
        print(*arr)
        return
    for i in range(1, n+1):
        if visited[i] == 0:
            visited[i] = 1
            arr[now] = i
            fun(now+1, step+1)
            visited[i] = 0

visited = [0 for _ in range(n+2)]

fun(0,0)
