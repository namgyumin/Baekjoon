import sys

n, m = map(int, sys.stdin.readline().split())


arr = [[0]* (n+1) for _ in range(n+1)]

for i in range(n) :
    temp = list(map(int, sys.stdin.readline().split()))
    
    for j in range(n+1):
        if j == 0:
            arr[i][j] = 0
        else:
            arr[i][j] = arr[i][j-1] + temp[j-1]


for _ in range(m):
    y1, x1, y2, x2 = map(int, sys.stdin.readline().split())
    
    result = 0
    
    for count in range(y1-1,y2,1):
        result += arr[count][x2] - arr[count][x1-1]

    print(result)
