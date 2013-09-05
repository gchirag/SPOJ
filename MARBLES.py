import sys
import math
t=int(raw_input())
while (t!=0) :
    t = t-1
    l = map(int,raw_input().split())
    n = l[0]
    r = l[1]
    n = n-1
    r = r-1
    a = 1
    b = 1
    while (r!=0):
        a = a * n
        b = b * r
        r = r-1
        n = n-1

    print a/b
