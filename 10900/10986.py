# 나머지 합
# 부분합

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

for i in range(1, n):
    arr[i] += arr[i-1]

cnt = [0] * m

for num in arr:
    cnt[num % m] += 1
result = cnt[0]
for i in range(m):
    if cnt[i] >= 2:
        result += cnt[i] * (cnt[i] - 1) / 2
print(int(result))