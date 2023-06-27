# 공주님의 정원
# Prioirty-Queue, Greedy

import sys
from heapq import heappush, heappop
n = int(sys.stdin.readline())

day = []
pq = []
for _ in range(n):
    ip = list(map(int, sys.stdin.readline().split()))
    day.append((ip[0]*100 + ip[1], ip[2]*100 + ip[3]))

cur = 301
i = 0
answer = 0
day.sort()

while i < len(day):
    if day[i][0] <= cur:
        heappush(pq, -day[i][1])
        i += 1
    else:
        break
while pq:
    top = -heappop(pq)
    if top > cur:
        answer += 1
        cur = top
        if top >= 1201:
            break
    while i < len(day):
        if day[i][0] <= cur:
            heappush(pq, -day[i][1])
            i += 1
        else:
            break
    
if cur >= 1201:
    print(answer)
else:
    print(0)
