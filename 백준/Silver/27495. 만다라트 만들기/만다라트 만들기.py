import sys

# 하드 코딩

class Semigoal:
    def __init__(self):
        self.keyword = ""
        self.arrary = []

    def defineKeyword(self, string):
        self.keyword = string

    def arraryAppend(self, string):
        self.arrary.append(string)

arr = []

for i in range(8):
    t = Semigoal()
    arr.append(t)

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))

for i in range(3):
    arr[0].arraryAppend(temp[i])
for i in range(3):
    arr[1].arraryAppend(temp[i+3])
for i in range(3):
    arr[2].arraryAppend(temp[i+6])

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))
arr[0].arraryAppend(temp[0])
arr[0].defineKeyword(temp[1])
arr[0].arraryAppend(temp[2])
arr[1].arraryAppend(temp[3])
arr[1].defineKeyword(temp[4])
arr[1].arraryAppend(temp[5])
arr[2].arraryAppend(temp[6])
arr[2].defineKeyword(temp[7])
arr[2].arraryAppend(temp[8])

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))

for i in range(3):
    arr[0].arraryAppend(temp[i])
for i in range(3):
    arr[1].arraryAppend(temp[i+3])
for i in range(3):
    arr[2].arraryAppend(temp[i+6])

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))

for i in range(3):
    arr[3].arraryAppend(temp[i])
for i in range(3):
    arr[4].arraryAppend(temp[i+6])

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))
arr[3].arraryAppend(temp[0])
arr[3].defineKeyword(temp[1])
arr[3].arraryAppend(temp[2])
arr[4].arraryAppend(temp[6])
arr[4].defineKeyword(temp[7])
arr[4].arraryAppend(temp[8])

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))

for i in range(3):
    arr[3].arraryAppend(temp[i])
for i in range(3):
    arr[4].arraryAppend(temp[i+6])

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))

for i in range(3):
    arr[5].arraryAppend(temp[i])
for i in range(3):
    arr[6].arraryAppend(temp[i+3])
for i in range(3):
    arr[7].arraryAppend(temp[i+6])

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))
arr[5].arraryAppend(temp[0])
arr[5].defineKeyword(temp[1])
arr[5].arraryAppend(temp[2])
arr[6].arraryAppend(temp[3])
arr[6].defineKeyword(temp[4])
arr[6].arraryAppend(temp[5])
arr[7].arraryAppend(temp[6])
arr[7].defineKeyword(temp[7])
arr[7].arraryAppend(temp[8])

temp = list(map(str, sys.stdin.readline().rstrip('\n').split(sep = " ")))

for i in range(3):
    arr[5].arraryAppend(temp[i])
for i in range(3):
    arr[6].arraryAppend(temp[i+3])
for i in range(3):
    arr[7].arraryAppend(temp[i+6])

arr.sort(key = lambda s : s.keyword)

for i in range(8):
    arr[i].arrary.sort()

for i in range(8):
    ret1 = "#" + str(i+1) + ". " + arr[i].keyword
    print(ret1)
    for j in range(8):
        ret2 = "#" + str(i+1) +"-"+ str(j+1)+ ". " + arr[i].arrary[j]
        print(ret2)
        
        
        
        