# 디펜스 게임
# priority queue
from heapq import heappop, heappush
def solution(n, k, enemy):
    answer = 0
    h = [] 
    for e in enemy:
        heappush(h,  -e)
        if n  >= e:
            n -= e
            answer += 1
            continue
        while k >= 1 and len(h) >= 1 and n < e:
            m = -heappop(h)
            n += m
            k -= 1
        if n  >= e:
            n -= e
            answer += 1
        else:
            break
    return answer