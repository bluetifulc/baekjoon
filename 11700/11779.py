import heapq
# 최소비용 구하기2
# Dijkstra

n = int(input())
m = int(input())
adj = [[] for _ in range(n+1)]

for _ in range(m):
    u,v,w = map(int, input().split())
    adj[u].append((w,v))

a,b = map(int, input().split())

path = [0] * (n+1)
dist = [1e9] * (n+1)
visited = [False] * (n+1)
q = [(0, a)]
path[a] = 0

while q:
    w, cur = heapq.heappop(q)
    if visited[cur]:
       continue
    visited[cur] = True
    for weight, next in adj[cur]:
        if weight + w < dist[next]:
            dist[next] = weight+w
            path[next] = cur
            heapq.heappush(q, (weight+w, next))

result = []
cur = b
while cur != a:
    result.append(str(cur))
    cur = path[cur]
result.append(str(a))
result.reverse()

print(dist[b])
print(len(result))
print(' '.join(result))
