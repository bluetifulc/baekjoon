# 합성함수와 쿼리
# Sparse-Array
import sys
input = sys.stdin.readline

m = int(input())
next = [[0] * 20 for _ in range(500001)]

a = list(map(int, input().split()))
for i in range(1, m+1):
    next[i][0] = a[i-1]

for i in range(1, 20):
    for j in range(1, 500001):
        next[j][i] = next[next[j][i-1]][i-1]

q = int(input())
for i in range(q):
    n, x = map(int, input().split())
    for j in range(20-1, -1, -1):
        if n & (1 << j):
            n -= (1 << j)
            x = next[x][j]
    print(x)
