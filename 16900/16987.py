# 계란으로 계란치기
# Back-tracking
import sys
input = sys.stdin.readline

n = int(input())
sw = [list(map(int, input().split())) for _ in range(n)]

def dfs(cur):
    if cur == n:
        return sum([sw[i][0] <= 0 for i in range(n)])
    if sw[cur][0] <= 0:
        return dfs(cur+1)
    ret = 0
    hit = False
    for i in range(n):
        if cur == i or sw[i][0] <= 0:
            continue
        hit = True
        sw[cur][0] -= sw[i][1]
        sw[i][0] -= sw[cur][1]
        ret = max(ret, dfs(cur+1))
        sw[cur][0] += sw[i][1]
        sw[i][0] += sw[cur][1]
    if not hit:
        return max(ret, sum([sw[i][0] <= 0 for i in range(n)]))
    return ret
print(dfs(0))