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
for _ in range(t):
    n,m = map(int,input().split())
    A = list(map(int,input().split()))
    g = [[] for _ in range(n)]
    ine = [0] * n
    for i in range(m):
        a,b=map(int,input().split())
        a,b=a-1,b-1
        g[a].append(b)
        ine[b] += 1
    r = []
    go = deque()
    INF = 1 << 30
    dist = [INF] * n
    for i in range(n):
        if ine[i] == 0:
            go.append(i)
            dist[i] = 0
    used = [0] * n
    while go:
        now = go.pop()
        r.append(now)
        used[now] = 1
        for nex in g[now]:
            if used[nex]:continue
            ine[nex] -= 1
            if ine[nex] == 0:
                go.append(nex)
    for i in range(n):
        fn = 0
        for j in r[::-1]:
            if A[j]:
                fn = 1
                A[j] -= 1
                for k in g[j]:
                    A[k] += 1
        if not fn:
            print(i)
            break
    else:            
        ans = 0
        for i in r:
            for j in g[i]:
                A[j] += A[i]
                A[j] %= mod
        print((n+A[r[-1]]) % mod)