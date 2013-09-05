import sys
while 1:
    try: k = raw_input()
    except EOFError: break
    k = int(k)
    if(k==1): print '1'
    else: print k+k-2
