# 달력
# 부분합
import sys
input = sys.stdin.readline

n = int(input())
ps = [0] * 367

for _ in range(n):
    u, v = map(int, input().split())
    ps[u] += 1
    ps[v+1] -= 1
    
for i in range(1, 367):
    ps[i] += ps[i-1]

result = 0

last = 0
height = 0
for i in range(1, 367):
    if ps[i] == 0:
        result += (i - last) * height
        height = 0
        continue
    elif height == 0:
        last = i
    height = max(height, ps[i])

print(result)