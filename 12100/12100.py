# 2048(Easy)
# Simulation, Implemetation
import sys
import copy
input = sys.stdin.readline

n = int(input())
dm = [[0,1],[0,-1],[1,0],[-1,0]]
a = [list(map(int, input().split())) for _ in range(n)]

def move(board, m):
    ret = copy.deepcopy(board)
    if m == 0:
        yr = range(0,n,1)
        xr = range(n-1,-1,-1)
    elif m == 1:
        yr = range(0,n,1)
        xr = range(0,n,1)
    elif m == 2:
        yr = range(n-1,-1,-1)
        xr = range(0,n,1)
    elif m == 3:
        yr = range(0,n,1)
        xr = range(0,n,1)

    for i in yr:
        for j in xr:
            if ret[i][j] == 0:
                continue
            y, x = i, j
            dy, dx = i + dm[m][0], j + dm[m][1]
            while dy >= 0 and dx >= 0 and dy < n and dx < n:
                if dy >= 0 and dx >= 0 and dy < n and dx < n:
                    if ret[dy][dx] == 0:
                        ret[dy][dx] = ret[y][x]
                        ret[y][x] = 0
                    else:
                        break
                y, x = dy, dx
                dy, dx = dy + dm[m][0], dx + dm[m][1]
    return ret

def merge(board, m):
    ret = copy.deepcopy(board)
    if m == 0:
        yr = range(0,n,1)
        xr = range(n-1,-1,-1)
    elif m == 1:
        yr = range(0,n,1)
        xr = range(0,n,1)
    elif m == 2:
        yr = range(n-1,-1,-1)
        xr = range(0,n,1)
    elif m == 3:
        yr = range(0,n,1)
        xr = range(0,n,1)

    for i in yr:
        for j in xr:
            if ret[i][j] == 0:
                continue
            dy, dx = i + dm[m][0], j + dm[m][1]
            if not (dy >= 0 and dx >= 0 and dy < n and dx < n):
                continue
            if ret[i][j] != ret[dy][dx]:
                continue
            ret[dy][dx] += ret[i][j]
            ret[i][j] = 0
    return ret

def find_max(board):
    ret = 0
    for i in range(n):
        for j in range(n):
            if board[i][j] >= ret:
                ret = board[i][j]
    return ret

def dfs(cur, board):
    if cur == 5:
        return find_max(board)
    ret = 0
    for i in range(4):
        b = move(board,i)
        b = merge(b,i)
        b = move(b,i)
        ret = max(ret, dfs(cur+1, b))
    return ret

print(dfs(0,a))