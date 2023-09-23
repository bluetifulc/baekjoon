# 노드사이의 거리
# BFS
import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]

for i in range(n-1):
    u,v,w = map(int, input().split())
    adj[u].append((w,v))
    adj[v].append((w,u))

INF = 123456789
for i in range(m):
    u, v = map(int, input().split())
    dist = [123456789] * (n+1)
    q = deque([u])
    dist[u] = 0
    while q:
        cur = q.popleft()
        if cur == v:
            break
        for w, next in adj[cur]:
            if dist[next] == 123456789:
                dist[next] = dist[cur] + w
                q.append(next)
    print(dist[v])
