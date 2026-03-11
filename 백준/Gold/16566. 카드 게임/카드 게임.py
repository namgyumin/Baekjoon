import sys
from bisect import bisect_right

input = sys.stdin.readline

n, m, k = map(int, input().split())

deck = sorted(map(int, input().split()))
matching = list(map(int, input().split()))
parent = [i for i in range(m+1)]

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

for j in matching:
    idx = bisect_right(deck, j)
    idx = find(idx)

    print(deck[idx])

    parent[idx] = find(idx+1)