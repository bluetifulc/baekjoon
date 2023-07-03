# 가운데에서 만나기
# Floyd-Warshall

import sys
input = sys.stdin.readline

n, m = map(int, input().split())

dist = [[1e9] * n for _ in range(n)]

for _ in range(m):
    u,v,w = map(int, input().split())
    dist[u-1][v-1] = w

k = int(input())
fs = list(map(int, input().split()))

for i in range(n):
    dist[i][i] = 0 

for k in range(n):
    for i in range(n):
        for j in range(n):
            if dist[i][j] > dist[i][k] + dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]

maxi = 1e9
result = []
for i in range(n):
    cur = 0
    for f in fs:
        cur = max(cur, dist[i][f-1] + dist[f-1][i])
    if cur < maxi:
        maxi = cur
        result.clear()
        result.append(i+1)
    elif cur == maxi:
        result.append(i+1)

for r in result:
    print(r, end=' ')
print('')