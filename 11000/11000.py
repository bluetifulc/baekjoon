# 강의실 배정
# Priority-Queue, Greedy

import sys
from heapq import heappop, heappush
input = sys.stdin.readline

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

a = sorted(a, key=lambda x: x[0])

pq = []
result = 0

for u,v in a:
    if not pq or u < pq[0]:   
        heappush(pq, v)
    else:
        heappop(pq)
        heappush(pq, v)


print(len(pq))