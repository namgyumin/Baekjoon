import sys

dirx = [-1, 1, 0, 0]
diry = [0, 0, -1, 1]

n = int(sys.stdin.readline())

arr = [[0 for _ in range(n)] for _ in range(n)] 
color_Arr = [[0 for _ in range(4)] for _ in range(n)]
for i in range(n):
    stri = sys.stdin.readline().rstrip('\n')
    temp = [word for word in stri]
    for j in range(n):
        if temp[j] == 'C':
            color_Arr[i][0] += 1
            arr[i][j] = 0
        elif temp[j] == 'P':
            color_Arr[i][1] += 1
            arr[i][j] = 1
        elif temp[j] == 'Z':
            color_Arr[i][2] += 1
            arr[i][j] = 2
        else: # 'Y'
            color_Arr[i][3] += 1
            arr[i][j] = 3
    
maxin = 0
for i in range(n):
    for j in range(n): ## 바꿀 값을 정할꺼임
        temp = arr[i][j] ## 바꿀 값의 원래 값을 저장 할거임
        for l in range(4): ## 값을 바꿔가면서
            ii = diry[l]
            jj = dirx[l]
            if(i+ii >= 0 and i + ii < n and j+jj >= 0 and j+jj < n):
                swap = arr[i][j]
                arr[i][j] = arr[i+ii][j+jj]
                arr[i+ii][j+jj] = swap
                run = 0
                before = -1
                for k in range(n): ## 전체 돌아갈꺼임
                    if before == -1:
                        before = arr[i][k]
                    if before == arr[i][k]:
                        run += 1
                        maxin = max(maxin, run)
                    else:
                        before = arr[i][k]
                        run = 1
                swap = arr[i][j]
                arr[i][j] = arr[i+ii][j + jj]
                arr[i + ii][j + jj] = swap
                    
for i in range(n):
    for j in range(n): ## 바꿀 값을 정할꺼임
        temp = arr[j][i] ## 바꿀 값의 원래 값을 저장 할거임
        for l in range(4): ## 값을 바꿔가면서
            ii = diry[l]
            jj = dirx[l]
            if(i+ii >= 0 and i + ii < n and j+jj >= 0 and j+jj < n):
                swap = arr[j][i]
                arr[j][i] = arr[j+jj][i+ii]
                arr[j+jj][i+ii] = swap
                run = 0
                before = -1
                for k in range(n): ## 전체 돌아갈꺼임
                    if before == -1:
                        before = arr[k][i]
                    if before == arr[k][i]:
                        run += 1
                        maxin = max(maxin, run)
                    else:
                        before = arr[k][i]
                        run = 1
                swap = arr[j][i]
                arr[j][i] = arr[j+jj][i+ii]
                arr[j+jj][i+ii] = swap
print(maxin)