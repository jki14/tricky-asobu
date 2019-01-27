import os

#def urandom32(low, hig):
    #with open('/dev/urandom', 'rb') as urand:
    #    foo = int(urand.read(8).encode('hex'), 16)
    #    urand.close()
    #    foo %= hig-low+1
    #    foo += low
    #    return foo

def urandom32(low, hig):
    foo = int(os.urandom(4).encode('hex'), 16)
    foo %= hig-low+1
    foo += low
    return foo 

print urandom32(0, 2147483647)
