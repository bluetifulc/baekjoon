# 혼자 놀기의 달인
# Disjoint-Set

par = [0] * 100
count = [1] * 100
visited = [False] * 100

def find(a):
    if par[a] == 0:
        return a
    par[a] = find(par[a])
    return par[a]

def union(a, b):
    a = find(a)
    b = find(b)
    if a==b:
        return
    par[a] = b
    count[b] += count[a]
    count[a] = 0

def solution(cards):
    answer = 0

    for i in range(len(cards)):
        union(i, cards[i]-1)
    
    candi = []
    for i in range(len(cards)):
        if count[i] != 0:
            candi.append(count[i])
            print(i , count[i])
    candi.append(0)
    candi.sort(key=lambda x: x, reverse=True)
    answer = candi[0] * candi[1]
    return answer