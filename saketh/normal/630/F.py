W = int(raw_input())

def ncr(n, r):
    res = 1
    for i in xrange(r + 1, n + 1):
        res *= i
    for i in xrange(1, n - r + 1):
        res /= i
    return res

print ncr(W, 5) + ncr(W, 6) + ncr(W, 7)