import sys 
n, m = map(int, sys.stdin.readline().split()) 

arr = []

def function(length):
    if len(arr) == m :
        print(*arr)
        return
    
    for i in range(length, n+1): 
        arr.append(i)
        function(i+1)
        arr.pop()
    
function(1)