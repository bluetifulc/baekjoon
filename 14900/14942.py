# 개미
# Sparse-Table, Tree
import sys
input = sys.stdin.readline

n = int(input())
ant = [int(input()) for _ in range(n)]
adj = [[] for _ in range(n+1)]

for i in range(n-1):
    u,v,w = map(int, input().split())
    adj[u].append((w,v))
    adj[v].append((w,u))

parent = [[0] * 18 for _ in range(n+1)]
energy = [[0] * 18 for _ in range(n+1)]
parent[1][0] = 1

def dfs(cur):
    for w, next in adj[cur]:
        if parent[next][0] == 0:
            energy[next][0] = w
            parent[next][0] = cur
            dfs(next)
dfs(1)

for i in range(1,18):
    for j in range(1, n+1):
        parent[j][i] = parent[parent[j][i-1]][i-1]
        energy[j][i] = energy[parent[j][i-1]][i-1] + energy[j][i-1]


for i in range(1, n+1):
    cur = i
    for j in range(17, -1, -1):
        if cur == 1:
            break
        if parent[cur][j] and energy[cur][j] <= ant[i-1]:
            ant[i-1] -= energy[cur][j]
            cur = parent[cur][j]
    print(cur)

