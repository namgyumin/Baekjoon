import sys
input = sys.stdin.readline

t = int(input())

def union_find(unio, i):
    if unio[i] >= 0:
        unio[i] = union_find(unio, unio[i])
        return unio[i]
    else:
        return i

def union_sum(unio, i, j):
    left = union_find(unio, i)
    right = union_find(unio, j)
    if left == right:
        print(-unio[left])
        return
    ret = 0
    ret -= unio[left]
    ret -= unio[right]
    unio[left] = right
    unio[right] = -ret
    print(ret)

def test():
    n = int(input())
    indexing = {}
    count = 0
    unio = []
    for i in range(n):
        st1, st2 = map(str, input().split())
        if indexing.get(st1) == None:
            indexing[st1] = count
            count += 1
            unio.append(-1)
        if indexing.get(st2) == None:
            indexing[st2] = count
            count += 1
            unio.append(-1)
        union_sum(unio, indexing[st1], indexing[st2])
        


for i in range(t):
    test()