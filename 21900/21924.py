# 도시건설
# Union-Find

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [list(map(int, input().split())) for _ in range(m)]
par = [-1 for _ in range(n+1)]

asc = sorted(adj, key=lambda x: x[2])

def find(a):
    if par[a] == -1:
        return a
    par[a] = find(par[a])
    return par[a]

def union(a, b):
    a, b = find(a), find(b)
    if a == b:
        return False
    par[b] = a
    return True

result = 0
cur = 1

for u, v, w in asc:
    if union(u, v):
        cur += 1
    else:
        result += w

if cur == n:
    print(result)
else:
    print(-1)