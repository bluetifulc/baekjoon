# 트리의 순회
# Tree

import sys
input = sys.stdin.readline
sys.setrecursionlimit(100007)

n = int(input())
ino = list(map(int, input().split()))
poo = list(map(int, input().split()))
where = [-1] * (n+1)

for i in range(n):
    where[ino[i]] = i

def solve(il, ir, pl, pr):
    if il > ir or pl > pr:
        return
    print(poo[pr], end=' ')
    root = where[poo[pr]]
    left_len = root - il
    right_len = ir - root

    solve(il, root-1, pl, pl + left_len -1)
    solve(root+1, ir, pr-right_len, pr-1)


solve(0,n-1,0,n-1)