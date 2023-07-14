# ABCDE
# Back-tracking, DFS

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

visited = [False] * n
def dfs(cur, depth):
    if depth == 5:
        return True
    result = False
    for next in adj[cur]:
        if not visited[next]:
            visited[next] = True
            result = dfs(next, depth+1)
            visited[next] = False
        if result:
            break
    return result

result = False
for i in range(n):
    visited[i] = True
    result = dfs(i, 1)
    visited[i] = False
    if result:
        break
if result:
    print(1)
else:
    print(0)