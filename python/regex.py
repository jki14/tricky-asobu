import re

# bar = r'(zzz$|xxx|e$)'
bar = r'zzz$|xxx|e$'
foo = r'Hellxxxo World!zzz'

print(re.sub(bar, '', foo))
