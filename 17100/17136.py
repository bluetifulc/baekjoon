# 색종이 붙이기
# DFS,Back-Tracking
import sys
input = sys.stdin.readline

paper = [list(map(int, input().split())) for _ in range(10)]
cnt = sum([sum(paper[i]) for i in range(10)])
def check(y,x,c):
    if y+c > 10 or x+c > 10:
        return False
    for i in range(y,y+c):
        for j in range(x,x+c):
            if paper[i][j] == 0:
                return False
    return True

def put(y,x,c,d):
    for i in range(y,y+c):
        for j in range(x,x+c):
            paper[i][j] = d

p = [5] * (5+1)
result = 123456789
cur = 0

def dfs(y,x):
    global cnt, result, cur
    if cnt == 0: # 다 붙임
        result = min(result, cur)
        return

    if x >= 10: # 다음 열
        dfs(y+1, 0)
        return
    
    if y >= 10 or cur >= result:
        return
    
    if paper[y][x] == 0: # 빠르게 넘기기
        dfs(y,x+1)
        return

    for k in range(1,6):
        if p[k] >= 1 and check(y,x,k):
            put(y,x,k,0)
            cnt -= k*k
            p[k] -= 1
            cur += 1
            dfs(y,x+k)
            cur -= 1
            p[k] += 1
            cnt += k*k
            put(y,x,k,1)

dfs(0,0)
if result == 123456789:
    print(-1)
else:
    print(result)