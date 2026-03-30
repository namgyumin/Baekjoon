import sys
from bisect import bisect_right

input = sys.stdin.readline

n, c = map(int, input().split())
arr = list(map(int, input().split()))

leftArr = arr[:n // 2]
rightArr = arr[n // 2:]

def make_sum_dict(arr):
    dic = {0: 1}
    
    for x in arr:
        temp = list(dic.items())
        for s, cnt in temp:
            dic[s + x] = dic.get(s + x, 0) + cnt
    
    return dic

leftDic = make_sum_dict(leftArr)
rightDic = make_sum_dict(rightArr)

right = sorted(rightDic.items())   

right_keys = [p[0] for p in right]

prefix = [0]
for k, v in right:
    prefix.append(prefix[-1] + v)

count = 0

for leftk, leftv in leftDic.items():
    limit = c - leftk
    idx = bisect_right(right_keys, limit)  
    count += leftv * prefix[idx]

print(count)