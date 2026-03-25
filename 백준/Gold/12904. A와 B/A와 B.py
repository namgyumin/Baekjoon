import sys

input = sys.stdin.readline

S = list(input().rstrip())
T = list(input().rstrip())

while len(T) > len(S):
    if T[-1] == 'A':
        T.pop()  
    elif T[-1] == 'B':
        T.pop() 
        T.reverse()  

if T == S:
    print(1)
else:
    print(0)