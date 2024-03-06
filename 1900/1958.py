# LCS 3
# DP
import sys
input = sys.stdin.readline

a = input().strip()
b = input().strip()
c = input().strip()

dp = [[[0] * 101 for _ in range(101)] for _ in range(101)]

for i in range(len(a)):
    for j in range(len(b)):
        for k in range(len(c)):
            if a[i] == b[j] == c[k]:
                dp[i+1][j+1][k+1] = dp[i][j][k] + 1
            else:
                dp[i+1][j+1][k+1] = max(dp[i][j+1][k+1], dp[i+1][j][k+1], dp[i+1][j+1][k])

print(dp[len(a)][len(b)][len(c)])