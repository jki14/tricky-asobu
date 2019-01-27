from Queue import Queue

class AhoCorasick:

    class ACNode:
        contained = None
        nextNodes = None
        failTo = None
        def __init__(self):
            self.contained = set()
            self.nextNodes = {}

    root = None
    def __init__(self, patterns):
        self.root = AhoCorasick.ACNode()
        for i in xrange(len(patterns)):
            cur = self.root
            for c in patterns[i]:
                if c not in cur.nextNodes.keys():
                    cur.nextNodes[c] = AhoCorasick.ACNode()
                cur = cur.nextNodes[c]
            cur.contained.add(i)
        bfsque = Queue()
        for path, node in self.root.nextNodes.iteritems():
            node.failTo = self.root
            bfsque.put(node)
        while not bfsque.empty():
            node = bfsque.get()
            for path, nextNode in node.nextNodes.iteritems():
                prev = node.failTo
                while prev!=self.root and path not in prev.nextNodes.keys():
                    prev = prev.failTo
                if path in prev.nextNodes.keys():
                    prev = prev.nextNodes[path]
                nextNode.contained |= prev.contained
                nextNode.failTo = prev
                bfsque.put(nextNode)

    def match(self, sample):
        foo = set()
        node = self.root
        for c in sample:
            while node!=self.root and c not in node.nextNodes.keys():
                node = node.failTo
            if c in node.nextNodes.keys():
                node = node.nextNodes[c]
            foo |= node.contained
        return foo

def main():
    patterns = []
    for i in xrange(int(raw_input().strip())):
        patterns.append(raw_input().strip())
    sample = ''
    for i in xrange(int(raw_input().strip())):
        sample += raw_input().strip()
    ahocorasick = AhoCorasick(patterns)
    print list(ahocorasick.match(sample))

if __name__ == '__main__':
    main()
