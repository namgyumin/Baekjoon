import sys

input = sys.stdin.readline

n = int(input())

dic = {}

for i in range(n):
    s = list(input().rstrip('\n'))
    s.reverse()
    l = len(s)
    count = 0
    for i in range(l):
        dic[s[i]] = dic.get(s[i], 0) + 10**count
        count += 1

lis = []

for i, v in dic.items():
    lis.append(v)

lis = sorted(dic.values(), reverse=True)

ret = 0
c = 9

for i in range(len(lis)):
    ret += c*lis[i]
    c -= 1
print(ret)