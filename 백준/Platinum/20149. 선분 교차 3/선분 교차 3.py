import sys
from decimal import Decimal, getcontext

getcontext().prec = 80 
def print_rational(num, den):
    if den < 0:
        num, den = -num, -den

    if num % den == 0:
        print(num // den, end="")
    else:
        s = format(Decimal(num) / Decimal(den), 'f').rstrip('0').rstrip('.')
        if s == "-0":
            s = "0"
        print(s, end="")

class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def ccw(A, B, C):
    v = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)
    if v > 0: return 1
    if v < 0: return -1
    return 0

def cross(A, B):
    return A.x * B.y - A.y * B.x

def crossAmBcCmD(a, b, c, d):
    e = point(a.x - b.x, a.y - b.y)
    f = point(c.x - d.x, c.y - d.y)
    return cross(e, f)

def isCross(A, B, C, D):
    ccw1 = ccw(A, B, C) * ccw(A, B, D)
    ccw2 = ccw(C, D, A) * ccw(C, D, B)

    if ccw1 <= 0 and ccw2 <= 0:
        if ccw1 == 0 and ccw2 == 0:
            if (A.x, A.y) > (B.x, B.y): A, B = B, A
            if (C.x, C.y) > (D.x, D.y): C, D = D, C
            return max((A.x, A.y), (C.x, C.y)) <= min((B.x, B.y), (D.x, D.y))
        return True
    return False

a, b, c, d = map(int, sys.stdin.readline().split())
A = point(a, b)
B = point(c, d)
a, b, c, d = map(int, sys.stdin.readline().split())
C = point(a, b)
D = point(c, d)

if isCross(A, B, C, D):
    print(1)

    den = crossAmBcCmD(B, A, D, C)   
    if den != 0:
        num = crossAmBcCmD(C, A, D, C)  

        px_num = A.x * den + (B.x - A.x) * num
        py_num = A.y * den + (B.y - A.y) * num

        print_rational(px_num, den)
        print(" ", end="")
        print_rational(py_num, den)
        print()
    else:
        if (A.x, A.y) > (B.x, B.y):
            A, B = B, A
        if (C.x, C.y) > (D.x, D.y):
            C, D = D, C

        start = max((A.x, A.y), (C.x, C.y))
        end   = min((B.x, B.y), (D.x, D.y))

        if start == end:
            print(start[0], start[1])
else:
    print(0)