import sys

class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def ccw(A, B, C):
    ccw = (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x)
    if ccw > 0: return 1
    if ccw < 0: return -1
    if ccw == 0: return 0

def isCross(A,B,C,D):
    ccw1 = ccw(A,B,C) * ccw(A,B,D)
    ccw2 = ccw(C,D,A) * ccw(C,D,B)
    
    if ccw1 <= 0 and ccw2 <= 0:
        if ccw1 == 0 and ccw2 == 0:
            return (min(A.x, B.x) <= max(C.x, D.x) and min(A.y, B.y) <= max(C.y, D.y) and min(C.x, D.x) <= max(A.x, B.x) and min(C.y, D.y) <= max(A.y, B.y))
        return True
    return False
    
a, b, c, d = map(int, sys.stdin.readline().split())
A = point(a,b)
B = point(c,d)
a, b, c, d = map(int, sys.stdin.readline().split())
C = point(a,b)
D = point(c,d)

if isCross(A,B,C,D) == True:
    print(1)
else:
    print(0)

