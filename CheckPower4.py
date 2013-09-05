import sys
def ispower(x):
    if(x==1):
        print ('yes')
        return 1
    ans = x&(x-1)
    if(ans!=0):
        print('no')
        return 0
    else:
        k = 1;
        for i in range (0,32):
            k = k<<2;
            if( x&k !=0):
                print ('yes')
                return 1
    
        print('no')
        return 0

for z in range(0,64):
    print(z,ispower(z))

    
    
