# 보이저 1호
# Implementation, Simulation
import sys
from collections import deque
input = sys.stdin.readline

next = [[3, 2, 1, 0], [1, 0, 3, 2]]
dm = [[-1,0], [0,1], [1,0], [0,-1]]
dir = ['U', 'R', 'D', 'L']

n, m = map(int, input().split())
space = [input() for _ in range(n)]
pr, pc = map(int, input().split())
pr -= 1
pc -= 1

result = -1
maxi = -1
inf = False
for i in range(4):
    q = deque()
    q.append((pr, pc, i))
    visited = [[[False] * 4 for _ in range(m)] for _ in range(n)]
    cur = 0
    # print(f'start {dir[i]}')
    while q:
        y, x, d = q.popleft()
        # print(f'{y} {x} {dir[d]}')

        if y < 0 or x < 0 or y >= n or x >= m or space[y][x] == 'C':
            if cur > maxi:
                maxi = cur
                result = i
            # print('end')
            break

        if visited[y][x][d]:
            if not inf:
                result = i
                maxi = 123456789
                inf = True
            # print('inf')
            break

        cur += 1
        visited[y][x][d] = True

        if space[y][x] == '\\':
            nextDir = next[0][d]
            dy, dx = y + dm[nextDir][0], x + dm[nextDir][1]
            q.append((dy, dx, nextDir))
            continue

        if space[y][x] == '/':
            nextDir = next[1][d]
            dy, dx = y + dm[nextDir][0], x + dm[nextDir][1]
            q.append((dy, dx, nextDir))
            continue

        # Default
        dy, dx = y + dm[d][0], x + dm[d][1]
        q.append((dy, dx, d))


print(dir[result])
if inf:
    print('Voyager')
else:
    print(maxi)