# 치즈
# BFS

from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
cheese = [list(map(int, input().split())) for _ in range(n)]
dm = [[0,1], [0,-1], [1,0], [-1,0]]
num = 0

tmpq = deque()

for i in range(n):
    num += sum(cheese[i])


last = 0
answer = 0
while num:
    answer += 1
    last = num
    # print(f'### {answer}')
    # for i in range(n):
    #     print(cheese[i])
    
    visited = [[False] * m for _ in range(n)]

    visited[0][0] = True
    q = deque()
    q.append((0,0))
    while q:
        y, x = q.popleft()
        for i in range(4):
            dy, dx = y + dm[i][0], x + dm[i][1]
            if dy >= 0 and dx >= 0 and dy < n and dx < m and not visited[dy][dx]:
                visited[dy][dx] = True
                if cheese[dy][dx] == 1:
                    num -= 1
                    cheese[dy][dx] = 0
                else:
                    q.append((dy, dx))
print(answer)
print(last)