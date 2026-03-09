import sys

input = sys.stdin.readline

n = int(input())

class clas:
    def __init__(self, start, end):
        self.start = start
        self.end = end
    
arr = []

for i in range(n):
    s,e = map(int, input().split())
    arr.append(clas(s,e))

sortArr = sorted(arr, key = lambda p : (p.end, p.start))

count = 0
end = 0

for i in sortArr:
    if i.start >= end:
        count += 1
        end = i.end

print(count)