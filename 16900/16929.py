# Two Dots
# DFS, Back-Tracking
import sys
input = sys.stdin.readline

n,m = map(int, input().split())
a = [input() for _ in range(n)]
visited = [[False] * m for _ in range(n)]
dm = [ [0,1], [0,-1], [1,0], [-1,0] ]

def dfs(y,x,sy,sx,w,c):
    for k in range(4):
        dy, dx = y + dm[k][0], x + dm[k][1]
        if dy >= 0 and dx >= 0 and dy < n and dx < m and a[dy][dx] == w:
            if dy == sy and dx == sx and c >= 3:
                return True
            if not visited[dy][dx]:
                visited[dy][dx] = True
                if dfs(dy,dx,sy,sx,w,c+1):
                    return True
                visited[dy][dx] = False
    return False

flag = False
for i in range(n):
    for j in range(m):
        visited[i][j] = True
        if dfs(i,j,i,j,a[i][j],1):
            flag = True
            break
        visited[i][j] = False
    if flag:
        break

if flag:
    print("Yes")
else:
    print("No")