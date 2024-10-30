#!/usr/bin/env PyPy3
from collections import Counter, defaultdict, deque
import collections
import itertools
import re
import math
from functools import reduce
import operator
import bisect
from heapq import *
import functools
import sys
mod = 10 ** 9 + 7
input = sys.stdin.readline


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
    s = input().rstrip()
    if s[0] == 'R' and (not ord('A') <= ord(s[1]) <= ord('Z')) and s.count('C'):
        cidx = s.index('C')
        #i1 = int(s[1:cidx])
        i2 = int(s[cidx+1:])
        ans = []
        while i2:
            x = (i2 - 1) % 26
            ans.append(chr(ord('A') + x))
            i2 -= 1
            i2 //= 26
        ans = ans[::-1]
        ans.append(s[1:cidx])
        print(''.join(ans))
    else:
        c = 0
        pos = 0
        for i in range(len(s)):
            if ord('A') <= ord(s[i]) <= ord('Z'):
                c *= 26
                c += ord(s[i]) - ord('A') + 1
            else:
                pos = i
                break
        ans = ['R']
        ans.append(s[pos:])
        ans.append('C')
        ans.append(str(c))
        print(''.join(ans))