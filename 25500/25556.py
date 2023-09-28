# 포스택
# Greedy
import sys
input = sys.stdin.readline

n = int(input())
perm = list(map(int, input().split()))

top = [0, 0, 0, 0]
flag = True

for i in range(n):
    cur = perm[i]
    maxi, maxidx = -1, -1
    
    # 가장 큰 값을 가진 스택 찾기
    for k in range(4):
        if top[k] < perm[i] and top[k] > maxi:
            maxi = top[k]
            maxidx = k
    
    if maxidx == -1:
        flag = False
        break

    top[maxidx] = perm[i]

if flag:
    print('YES')
else:
    print('NO')