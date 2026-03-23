import sys

def function(arr, i, j):
    lis = []
    for k in range(j, i-1, -1):
        lis.append(arr[k])
    for  k in range(0, j-i+1):
        arr[i+k] = lis[k]

n, k = map(int, sys.stdin.readline().split())

arr = []

for i in range(1, n+1):
    arr.append(i)

for i in range(k):
    i, j = map(int, sys.stdin.readline().split())
    function(arr, i-1, j-1)


for i in range(0, n):
    print(arr[i], end = " ")