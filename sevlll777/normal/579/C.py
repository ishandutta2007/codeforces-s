a, b = map(int, input().split())
if a < b:
    print(-1)
else:
    print((a + b) / (2 * ((a + b) // (2 * b))))