# 장미
# Math, Brute-Force

import sys
input = sys.stdin.readline

n,a,b,c,d = map(int, input().split())

if c * b > a * d:
    a,b,c,d = c,d,a,b

result = 1e17
for i in range(a):
    cur = i * d
    if n - i * c - 1 < 0:
        result = min(result, cur)
        break
    cur += (((n - i * c - 1) // a) + 1) * b
    result = min(result, cur)

print(result)