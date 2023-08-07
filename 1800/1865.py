# 웜홀
# Bellman-Ford
import sys
input = sys.stdin.readline
INF = int(1e9)

tc = int(input())

for tt in range(tc):
    n, m, w = map(int, input().split())
    adj = []
    for mm in range(m):
        s, e, t = map(int, input().split())
        adj.append((s,e,t))
        adj.append((e,s,t))
    for ww in range(w):
        s, e, t = map(int, input().split())
        adj.append((s,e,-t))
    
    dist = [INF] * (n+1)
    for i in range(n-1):
        for s,e,t in adj:
            if dist[e] > dist[s] + t:
                dist[e] = dist[s] + t

    flag = False
    for s,e,t in adj:
        if dist[e] > dist[s] + t:
            flag = True

    if flag:
        print("YES")
    else:
        print("NO")