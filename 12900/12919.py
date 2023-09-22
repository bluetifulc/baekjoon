# A와 B 2
# String
from collections import deque
import sys
input = sys.stdin.readline

s = list(input().strip())
t = list(input().strip())

def dfs(s, t):
    if s == t:
        return True
    if len(t) == 0:
        return False
    if t[-1] == 'A' and dfs(s, t[:-1]):
        return True
    if t[0] == 'B' and dfs(s, t[::-1][:-1]):
        return True
    return False

if dfs(s,t):
    print(1)
else:
    print(0)