import sys
def binaryeq(x):
    if(x==0): return
    s=x%2
    binaryeq(x/2)
    print s

binaryeq(6)
