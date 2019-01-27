class Kmp:
    pattern = None
    length = 0
    failed = None
    def __init__(self, pattern):
        self.pattern = pattern
        self.length = len(pattern)
        self.failed = [-1 for i in xrange(self.length)]
        prev = -1
        for i in xrange(1, self.length):
            while prev!=-1 and self.pattern[prev+1]!=self.pattern[i]:
                prev = self.failed[prev]
            if self.pattern[prev+1]==self.pattern[i]:
                prev += 1
            self.failed[i] = prev
    def match(self, sample):
        foo = []
        curr = -1
        for i in xrange(0, len(sample)):
            while curr!=-1 and self.pattern[curr+1]!=sample[i]:
                curr = self.failed[curr]
            if self.pattern[curr+1]==sample[i]:        
                curr += 1
            if curr==self.length-1:
                foo.append(i)
                curr = self.failed[curr]
        return foo

def main():
    pat = raw_input().strip()
    kmp = Kmp(pat)
    sample = raw_input().strip()
    foo=kmp.match(sample)
    print foo

if __name__ == '__main__':
    main()
