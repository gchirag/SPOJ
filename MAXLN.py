import sys
t=int(raw_input())
count = 0
while (t!=0) :
    t = t-1
    count = count + 1
    r = int(raw_input())
    print "Case %d: %0.2f" %(count,4*r*r+0.25)
