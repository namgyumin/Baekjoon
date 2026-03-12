import sys

input = sys.stdin.readline

n,m = map(int,input().split())

dir = {}
string = []
string.append(" ")
for i in range(1, n+1):
    temp = input().rstrip('\n')
    string.append(temp)
    dir[temp] = dir.get(temp, 0) + i

for j in range(m):
    temp = input().rstrip('\n')
    if dir.get(temp) == None:
        temp = int(temp)
        print(string[temp])
    else:
        print(dir.get(temp))