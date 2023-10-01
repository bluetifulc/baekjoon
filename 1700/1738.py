# 골목길
# Bellman-Ford
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]

for _ in range(m):
    u,v,w = map(int, input().split())
    adj[u].append((-w,v))

dist = [123456789] * (n+1)
pre = [0] * (n+1)
dist[1] = 0

for i in range(n-1):
    for cur in range(1, n+1):
        for w, next in adj[cur]:
            if dist[cur] != 123456789 and dist[next] > dist[cur] + w:
                dist[next] = dist[cur] + w
                pre[next] = cur

                    
for cur in range(1, n+1):
    for w, next in adj[cur]:
        if dist[cur] != 123456789 and dist[next] > dist[cur] + w:
            dist[next] = -123456789

if abs(dist[n]) == 123456789:
    print(-1)
else:
    cur = n
    result = []
    while cur != 0:
        result.append(cur)
        cur = pre[cur]
    for i in result[::-1]:
        print(i, end=' ')
