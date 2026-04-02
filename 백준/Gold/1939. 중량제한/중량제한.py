import sys

input = sys.stdin.readline

n, m = map(int, input().split())

class brige:
    def __init__(self, to, value):
        self.to = to
        self.value = value

briges = [[] for _ in range(n+1)]

for i in range(m):
    a, b, c = map(int, input().split())
    briges[a].append(brige(b, c))
    briges[b].append(brige(a, c))

f, t = map(int, input().split())

small = 0
big = 1000000000

def canGo(weight):
    global f, t, n
    
    vis = [-1 for _ in range(n+1)]
    
    que = []
    que.append(f)
    q = 0
    vis[f] = 1
    
    while len(que) > q:
        temp = que[q]
        q += 1
        for i in briges[temp]:
            if vis[i.to] == -1:
                if i.value >= weight:
                    if i.to == t:
                        return 1
                    que.append(i.to)
                    vis[i.to] = 1
    return 0

ans = 0
while big >= small:
    mid = (big + small) //2 
    if canGo(mid) == 1:
        ans = mid
        small = mid + 1
    else:
        big = mid - 1

print(ans)



