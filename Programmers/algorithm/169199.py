from collections import deque
# 리코쳇 로봇
# BFS

def solution(board):
    R,C = len(board), len(board[0])
    dm = [[0,1], [0,-1], [1,0], [-1, 0]]
    q = deque()
    srcr, srcc, destr, destc = 0, 0, 0, 0 
    for r in range(0,R):
        for c in range(0,C):
            if board[r][c] == 'R':
                srcr, srcc = r, c
            if board[r][c] == 'G':
                destr, destc = r, c
    visited = [[False] * C for _ in range(R)]
    q.append((srcr, srcc))
    visited[srcr][srcc] = True
    
    answer = 0
    flag = False
    y, x = 0, 0
    while q:
        qsize = len(q)
        while qsize:
            qsize -= 1
            y, x = q.popleft()
            if y == destr and x == destc:
                flag = True
                break
            for d in range(4):
                dy, dx = y, x
                ny, nx = dm[d]
                while dy + ny >= 0 and dx + nx >= 0 and dy + ny < R and dx + nx < C and board[dy + ny][dx + nx] != 'D':
                    dy, dx = dy + dm[d][0], dx + dm[d][1]
                if not visited[dy][dx]:
                    q.append((dy,dx))
                    visited[dy][dx] = True
        if flag:
            break
        answer += 1

    if not flag:
        answer = -1
    return answer