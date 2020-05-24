import os
import sys

#def urandom32(low, hig):
    #with open('/dev/urandom', 'rb') as urand:
    #    foo = int(urand.read(8).encode('hex'), 16)
    #    urand.close()
    #    foo %= hig-low+1
    #    foo += low
    #    return foo

def urandom32(low, hig):
    foo = os.urandom(4).hex() \
              if sys.version_info >= (3, 0) else os.urandom(4).encode('hex')
    foo = int(foo, 16)
    foo %= hig-low+1
    foo += low
    return foo 

print(urandom32(0, 2147483647))
