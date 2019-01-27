class Trie:

    class _TrieNode:
        contained = None
        nextNodes = None
        def __init__(self):
            self.contained = set()
            self.nextNodes = {}

    _root = None

    def __init__(self, words):
        self._root = Trie._TrieNode()
        for i in xrange(len(words)):
            cur = self._root
            for c in words[i]:
                if c not in cur.nextNodes.keys():
                    cur.nextNodes[c] = Trie._TrieNode()
                cur = cur.nextNodes[c]
            cur.contained.add(i)

    def count_leafs(self):
        return self._count_leafs(self._root)

    def _count_leafs(self, node):
        if node:
            if node.nextNodes:
                foo = 0
                for nextNode in node.nextNodes.values():
                    foo += self._count_leafs(nextNode)
                return foo
            else:
                return 1
        else:
            return 0


def main():
    prefixes = []
    suffixes = []
    with open('5000-most-common-words-in-english.csv', 'r') as wfile:
        for line in wfile:
            word = line.strip()
            prefixes.append(word)
            suffixes.append(word[::-1])
    prefix_trie = Trie(prefixes)
    suffix_trie = Trie(suffixes)
    print('words list size = %d' % len(prefixes))
    print('prefix_trie leafs num = %d' % prefix_trie.count_leafs())
    print('suffix_trie leafs num = %d' % suffix_trie.count_leafs())


if __name__ == '__main__':
    main()
