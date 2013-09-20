import sys
n,d=raw_input().split()
n=int(n)
d=int(d)
while (not(d==0 and n==0)):    
    print pow(n,d)
    n,d=raw_input().split()
    n=int(n)
    d=int(d)
