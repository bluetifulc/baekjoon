# 최솟값 찾기
# Deque, Sliding Window

from collections import deque

n, l = map(int, input().split())
ip = list(map(int, input(). split()))

dq = deque()

for i in range(n):
    while dq and dq[-1][0] > ip[i]:
        dq.pop()

    while dq and dq[0][1] < i - l + 1:
        dq.popleft()

    dq.append((ip[i], i))
    print(dq[0][0], end=' ')
print()