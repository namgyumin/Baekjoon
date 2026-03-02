import sys
from itertools import combinations

n = int(sys.stdin.readline())
arr = [[]for _ in range(n)]

for i in range(n):
    arr[i] = list(map(int, sys.stdin.readline().split()))

a_all = set(range(1, n + 1))

minin = 10**18

half = int(n/2)
for comb in combinations(range(1, n + 1), half):
    a = set(comb)
    b = a_all - a

    counta = 0
    for i, j in combinations(a, 2):
        counta += arr[i-1][j-1] + arr[j-1][i-1]

    countb = 0
    for i, j in combinations(b, 2):
        countb += arr[i-1][j-1] + arr[j-1][i-1]

    count = abs(counta - countb)
    if count < minin:
        minin = count

print(minin)