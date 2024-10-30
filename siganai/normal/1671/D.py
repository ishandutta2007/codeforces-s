#!/usr/bin/env PyPy3

from collections import Counter, defaultdict, deque
import itertools
import re
import math
from functools import reduce
import operator
import bisect
import heapq
import functools
mod=10**9+7

import sys
input=sys.stdin.readline

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
INF = 1 << 31
t = int(input())
for _ in range(t):
    n,x=map(int,input().split())
    a = list(map(int,input().split()))
    ans = 0
    for i in range(1,n):
        ans += abs(a[i] - a[i-1])
    mi = min(a)
    ma = max(a)
    if mi > 1:
        tmp = min(a[0] - 1,a[-1] - 1)
        tmp = min(tmp,(mi-1)*2)
        ans += tmp
    if ma < x:
        tmp = min(-a[0] + x,-a[-1] + x)
        tmp = min(tmp,(x-ma) * 2)
        ans += tmp
    print(ans)