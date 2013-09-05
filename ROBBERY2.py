import sys
import math
t=int(raw_input())
while (t!=0) :
    t = t-1
    l = map(int,raw_input().split())
    n = l[0]
    k = l[1]
    a = [0]*k
    count = 0;
    p = int((math.sqrt(1+8*n)-1)/2)
    row = p/k
    col = p%k
    last = n - p*(p+1)/2
    for i in range(0,col):
        a[i] = row*(row+1)*k/2+ (row+1)*(i+1)
    a[col] = row*(row-1)*k/2+ last + (row)*((col+1))
    for i in range(col+1,k):
        a[i] = row*(row-1)*k/2+ (row)*(i+1)
    for i in range(0,k):
        print a[i]

        
    
'''    while(n!=0):
        for i in range(0,k):
            if (n > count + i):
                a[i] = a[i] + count + i
                n = n - count -i
            else :
                a[i] = a[i] + n
                n = 0
        count = count + k
    for i in range (0,k):
        print a[i]
'''
'''
    print n
    print k
    a = [0]*k
    p = n/k/(k+1)*2
    print p
    q = n - p*k*(k+1)/2
    print 'q',q
'''
'''    for i in range (1,k):
        if(q>p+i):
            a[i]=i*p + k * (p-1)*p/2 + p + i
        else:
            a[i]=i*p + k * (p-1)*p/2 + q
        q = q-p-i
        print a[i],' '
    print "\n"
'''
