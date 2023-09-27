# LCA 2
# Sparse-Table, LCA
import sys
input = sys.stdin.readline
sys.setrecursionlimit(100001)

n = int(input())
adj = [[] for _ in range(n+1)]

for i in range(n-1):
    u,v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

parent = [[0] * 18 for _ in range(n+1)]
depth = [0] * (n+1)
parent[1][0] = -1

def dfs(cur):
    for next in adj[cur]:
        if parent[next][0] == 0:
            parent[next][0] = cur
            depth[next] = depth[cur] + 1
            dfs(next)
dfs(1)

for j in range(1, 18):
    for i in range(1, n+1):
        parent[i][j] = parent[parent[i][j-1]][j-1]

def lca(u, v):
    if depth[v] > depth[u]:
        u,v = v,u
    diff = depth[u] - depth[v]
    for i in range(0, 18):
        if diff & (1 << i):
            u = parent[u][i]
   
    if u != v:
        for i in range(17, -1, -1):
            if parent[u][i] != -1 and parent[u][i] != parent[v][i]:
                u = parent[u][i]
                v = parent[v][i]
        u = parent[u][0]
    return u

m = int(input())
for i in range(m):
    u, v = map(int, input().split())
    print(lca(u,v))