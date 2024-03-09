# 배수 공사
# DP, Knapsack
import sys
input = sys.stdin.readline

n, x = map(int, input().split())
pipe = []

for _ in range(n):
    l, c = map(int, input().split())
    pipe.append((l, c))

dp = [[-1] * 101 for _ in range(10001)]

def solve(n, idx):
    if n == 0:
        return 1
    if idx == len(pipe) or n < 0:
        return 0
    if dp[n][idx] != -1:
        return dp[n][idx]
    dp[n][idx] = 0
    for i in range(pipe[idx][1]+1):
        dp[n][idx] += solve(n - pipe[idx][0] * i, idx+1)
    return dp[n][idx]

print(solve(x, 0))