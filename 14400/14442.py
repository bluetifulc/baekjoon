# 벽 부수고 이동하기 2
# BFS
from collections import deque
import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
mapp = [input().strip() for _ in range(n)]
visited = [[[False] * (k+1) for _ in range(m)] for _ in range(n)]
dm = [[0,1],[0,-1],[1,0],[-1,0]]

q = deque()
q.append((0,0,k))
visited[0][0][k] = True
result = 0
flag = False
while q:
    qSize = len(q)
    result += 1
    for _ in range(qSize):
        y,x,w = q.popleft()
        if y == n-1 and x == m-1:
            flag = True
            break
        for i in range(4):
            dy,dx = y + dm[i][0], x + dm[i][1]
            if dy >= 0 and dx >= 0 and dy < n and dx < m:
                if mapp[dy][dx] == '0' and not visited[dy][dx][w]:
                    q.append((dy,dx,w))
                    visited[dy][dx][w] = True
                if mapp[dy][dx] == '1' and w and not visited[dy][dx][w-1]:
                    q.append((dy,dx,w-1))
                    visited[dy][dx][w-1] = True
    if flag:
        break

if flag:
    print(result)
else:
    print(-1)