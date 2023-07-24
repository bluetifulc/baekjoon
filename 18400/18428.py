# 감시피하기
# Backtracking

import sys
input = sys.stdin.readline

n = int(input())
arr = [list(input().split()) for _ in range(n)]
t = []
X = []
dm = [[1,0],[-1,0],[0,1],[0,-1]]

for i in range(n):
    for j in range(n):
        if arr[i][j] == 'X':
            X.append((i,j))
        elif arr[i][j] == 'T':
            t.append((i,j))

def check():
    flag = True
    for y,x in t:
        for i in range(4):
            ny, nx = y, x
            while ny >= 0 and nx >= 0 and ny < n and nx < n:
                if arr[ny][nx] == 'S':
                    flag = False
                elif arr[ny][nx] == 'O':
                    break
                ny += dm[i][0]
                nx += dm[i][1]
    return flag

def dfs(cur, o):
    if o == 3:
        if check():
            return 1
        return 0
    if cur >= len(X):
        return 0
    result = dfs(cur+1, o)

    y, x = X[cur]
    arr[y][x] = 'O'
    result = max(result, dfs(cur+1, o+1))
    arr[y][x] = 'X'
    return result

if dfs(0,0):
    print('YES')
else:
    print('NO')