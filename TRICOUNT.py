import sys
t = int(raw_input())
while t>0:
    t = t-1
    n = int(raw_input())
    print (n*(n+2)*(2*n+1) -n%2)/8
    
