import sys

def test():
    vertex, edge = map(int, sys.stdin.readline().split())
    arr = [[] for _ in range(vertex+1)]
    for _ in range(edge):
        x, y = map(int, sys.stdin.readline().split())
        arr[x].append(y)
        arr[y].append(x)

    visited = [0 for _ in range(vertex+1)]
    for i in range(1, vertex+1):
        if visited[i] == 0:
            que = [i]
            count = 0
            visited[i] = 1
            for j in arr[i]:
                if(visited[j] == 0):
                    visited[j] = -1
                    que.append(j)
            while count < len(que):
                node = que[count]
                count += 1
                temp = visited[node]
                for k in arr[node]:
                    if(visited[k] == 0):
                        visited[k] = -temp
                        que.append(k)
                    elif(visited[k] == temp):
                        print("NO")
                        return
    print("YES")
    return
                


t = int(sys.stdin.readline())
for i in range(t):
    test()