# 수확
# DP

import sys
sys.setrecursionlimit(3001)
input = sys.stdin.readline

n = int(input())
rice = [int(input()) for _ in range(n)]

cache = [[0] * n for _ in range(n)]

def dp(start, end, cnt):
    if start == end:
        return rice[start] * cnt
    if cache[start][end] != 0:
        return cache[start][end]
    cache[start][end] = max(rice[start] * cnt + dp(start+1, end, cnt+1), rice[end] * cnt + dp(start, end-1, cnt+1))
    return cache[start][end]

print(dp(0, n-1, 1))