# 연구소3
# BFS, Combination, Implementation
import sys
import copy
from itertools import combinations
from collections import deque
input = sys.stdin.readline

dm = [ [0,1], [0,-1], [1,0], [-1,0] ]
n, m = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(n)]
ml = []
mc = 0
for i in range(n):
    for j in range(n):
        if l[i][j] == 2:
            ml.append((i,j))
        elif l[i][j] == 0:
            mc += 1
comb = list(combinations([i for i in range(len(ml))], m))
result = 1000000

def bfs(p):
    global result
    time = 0
    c = mc
    tl = copy.deepcopy(l)
    q = deque()
    for i in range(m):
        q.append((ml[p[i]][0], ml[p[i]][1]))
        tl[ml[p[i]][0]][ml[p[i]][1]] = 3
    while c > 0:
        qs = len(q)
        for i in range(qs):
            y, x = q.popleft()
            for k in range(4):
                dy, dx = y + dm[k][0], x + dm[k][1]
                if dy >= 0 and dx >= 0 and dy < n and dx < n:
                    if tl[dy][dx] == 0:
                        c -= 1
                        tl[dy][dx] = 3
                        q.append((dy, dx))  
                    elif tl[dy][dx] == 2:
                        tl[dy][dx] = 3
                        q.append((dy, dx))
        time += 1
        if time > result or not q:
            break
    if c == 0:
        result = min(result, time)

for p in comb:
    bfs(p)

if result == 1000000:
    print(-1)
else:
    print(result)