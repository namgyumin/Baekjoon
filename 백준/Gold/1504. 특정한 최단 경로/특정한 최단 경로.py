import sys

input = sys.stdin.readline

class brige:
    def __init__(self,go,value):
        self.go = go
        self.value = value


v, e = map(int, input().split())
arr = [[]for _ in range(v)]

for _ in range(e):
    a,b,c = map(int, input().split())
    arr[a-1].append(brige(b-1,c))
    arr[b-1].append(brige(a-1,c))

v1, v2 = map(int, input().split())

v1 -= 1
v2 -= 1

def func(v1, v2):
    global v
    visited = [-1 for _ in range(v)]

    queue = []
    queue.append(0)
    q = 0
    visited[0] = 0

    while q < len(queue):
        temp = queue[q]
        q += 1
        for i in arr[temp]:
            if visited[i.go] == -1 or visited[i.go] > visited[temp] + i.value:
                visited[i.go] = visited[temp] + i.value
                queue.append(i.go)
    if visited[v1] == -1:
        return -1
    
    queue = []
    queue.append(v1)
    q = 0
    for i in range(v):
        if i != v1:
            visited[i] = -1

    while q < len(queue):
        temp = queue[q]
        q += 1
        for i in arr[temp]:
            if visited[i.go] == -1 or visited[i.go] > visited[temp] + i.value:
                visited[i.go] = visited[temp] + i.value
                queue.append(i.go)
    
    if visited[v2] == -1:
        return -1

    queue = []
    queue.append(v2)
    q = 0
    for i in range(v):
        if i != v2:
            visited[i] = -1

    while q < len(queue):
        temp = queue[q]
        q += 1
        for i in arr[temp]:
            if visited[i.go] == -1 or visited[i.go] > visited[temp] + i.value:
                visited[i.go] = visited[temp] + i.value
                queue.append(i.go)

    return visited[v-1]

a1 = func(v1, v2)
a2 = func(v2, v1)


if a1 == -1 and a2 == -1:
    print(-1)
elif a1 == -1:
    print(a2)
elif a2 == -1:
    print(a1)
else:
    print(min(a1, a2))
            


