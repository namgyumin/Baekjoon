import sys
import heapq

input = sys.stdin.readline

class classTime:
    def __init__(self, start, end):
        self.start = start
        self.end = end
    
n = int(input())
classArr = []

for i in range(n):
    s, e = map(int, input().split())
    temp = classTime(s, e)
    classArr.append(temp)

sortedArr = sorted(classArr, key=lambda p: p.start)

classRoom = []

for clas in sortedArr:
    if len(classRoom) == 0:
        heapq.heappush(classRoom, clas.end)
        continue

    t = heapq.heappop(classRoom)
    if t <= clas.start:
        heapq.heappush(classRoom, clas.end)
    else:
        heapq.heappush(classRoom, t)
        heapq.heappush(classRoom, clas.end)

print(len(classRoom))