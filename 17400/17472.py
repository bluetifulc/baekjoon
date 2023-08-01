# 다리 만들기 2
# Implementation, DFS, Union-Find
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
b = [[0] * m for _ in range(n)]
dm = [[0,1],[0,-1],[1,0],[-1,0]]
visit = [[False] * m for _ in range(n)]

def dfs(y, x, c):
    for i in range(4):
        dy, dx = y + dm[i][0], x + dm[i][1]
        if dy >= 0 and dx >= 0 and dy < n and dx < m and not visit[dy][dx]:
            visit[dy][dx] = True
            if a[dy][dx] == 1:
                b[dy][dx] = c
                dfs(dy, dx, c)

cur = 1
for y in range(n):
    for x in range(m):
        if not visit[y][x] and a[y][x] == 1:
            visit[y][x] = True
            b[y][x] = cur
            dfs(y, x, cur)
            cur += 1
cur -= 1

adj = []
for y in range(n):
    for x in range(m):
        if b[y][x] != 0:
            dy, dx = y, x
            for i in range(4):
                cnt = -1
                while True:
                    dy += dm[i][0]
                    dx += dm[i][1]
                    cnt += 1
                    if dy < 0 or dx < 0 or dy >= n or dx >= m:
                        break
                    if b[dy][dx] != 0:
                        if b[dy][dx] == b[y][x] or cnt < 2:
                            break
                        adj.append((b[y][x],b[dy][dx],cnt))
                        break

adj = sorted(adj, key=lambda x: x[2])
par = [-1] * (cur+1)
def find(a):
    if par[a] == -1:
        return a
    par[a] = find(par[a])
    return par[a]
def union(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return False
    par[b] = a
    return True

curi = 1
result = 0
for u,v,w in adj:
    if union(u,v):
        result += w
        curi += 1
        if curi == cur:
            break

if curi == cur:
    print(result)
else:
    print(-1)