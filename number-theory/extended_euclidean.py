# extended_euclidean, ax≡c(mod b)
# equation: ax + by = c
# equation is valid if and only if c % gcd(a, b) == 0
# X = x + b / gcd(a, b) * k
# Y = x - a / gcd(a, b) * k

# recursive version
def extended_euclidean(a, b):
    if b != 0:
        g, x, y = extended_euclidean(b, a % b)
        return g, y, x - a / b * y
    else:
        return a, 1, 0

def inverse(a, b):
    return extended_euclidean(a, b)[1]
