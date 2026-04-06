import sys

input = sys.stdin.readline

a = int(input())
b = int(input())
c = int(input())

print(a+b-c)
alist = str(a)
blist = str(b)
alist += blist

total = int(alist)
print(total-c)