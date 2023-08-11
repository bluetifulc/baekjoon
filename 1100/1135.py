# 뉴스 전하기
# Tree, DFS
import sys
input = sys.stdin.readline

n = int(input())
par = list(map(int, input().split()))

children = [[] for _ in range(n)]

for i in range(1, n):
    children[par[i]].append(i)

def dfs(cur):
    if not children[cur]:
        return 1
    tmp = []
    for child in children[cur]:
        tmp.append(dfs(child))
    tmp = sorted(tmp, key = lambda x: -x)

    ret = 0
    for i in range(len(children[cur])):
        ret = max(ret, tmp[i] + i + 1)
    return ret

print(dfs(0)-1)