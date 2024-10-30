#!/usr/bin/env PyPy3

from collections import Counter, defaultdict, deque
import itertools
import re
import math
from functools import reduce
import operator
import bisect
from heapq import *
import functools
mod=998244353

import sys
import os
from io import BytesIO, IOBase
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
t = int(input())

INF = 1 << 31
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    s = input().rstrip()
    wbcnt = [[0] * n for _ in range(2)]
    g = [[] for _ in range(n)]
    for i in range(n - 1):
        g[a[i] - 1].append(i + 1)
    par = [-1] * n
    r = []
    go = deque([0])
    while go:
        now = go.pop()
        r.append(now)
        for nex in g[now]:
            par[nex] = now
            #g[nex].remove(now)
            go.append(nex)
    for i in r[1:][::-1]:
        if s[i] == 'W':
            wbcnt[0][i] += 1
        else:
            wbcnt[1][i] += 1
        wbcnt[0][par[i]] += wbcnt[0][i]
        wbcnt[1][par[i]] += wbcnt[1][i]
    if s[0] == 'W':
        wbcnt[0][0] += 1
    else:
        wbcnt[1][0] += 1
    ans = 0
    for i in range(n):
        if wbcnt[0][i] == wbcnt[1][i]:
            ans += 1
    print(ans)