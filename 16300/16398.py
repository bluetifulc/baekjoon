# 행성 연결
# Spanning Tree

import sys

n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
par = [i for i in range(n)]

def find(a):
    if par[a] == a:
        return a
    par[a] = find(par[a])
    return par[a]

def union(a, b):
    a, b = find(a), find(b)
    if a == b:
        return False
    par[b] = a
    return True

edges = []

for i in range(n):
    for j in range(i+1, n):
        if arr[i][j] != 0:
            edges.append((arr[i][j], i, j))
edges.sort()

answer = 0
for edge in edges:
    w, a, b = edge
    if union(a, b):
        answer += w
print(answer)