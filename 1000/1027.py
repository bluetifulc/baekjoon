# 고층 건물
# Mathematics, Brute-Force

import sys
input = sys.stdin.readline

n = int(input())
bs = list(map(int, input().split()))

def grad(x1, y1, x2, y2):
    return (y2-y1) / (x2-x1)

answer = 0

for idx, b in enumerate(bs):
    cur, l, r = 0, float('inf'), -float('inf')
    for i in range(idx+1, n):
        tmp = grad(idx, b, i, bs[i])
        if tmp > r:
            r = tmp
            cur += 1
    for i in range(idx-1, -1, -1):
        tmp = grad(i, bs[i], idx, b)
        if tmp < l:
            l = tmp
            cur += 1
    answer = max(answer, cur)

print(answer)