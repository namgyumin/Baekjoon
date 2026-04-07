import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(map(int, input().split()))

vis = []

arr.sort()

def baT():
    global m, n
    if len(vis) == m:
        for i in vis:
            print(i, end= " ")
        print()
        return
    for i in range(n):
        if len(vis) ==  0 or vis[-1] <= arr[i]:
            vis.append(arr[i])
            baT()
            vis.pop()
    

baT()
