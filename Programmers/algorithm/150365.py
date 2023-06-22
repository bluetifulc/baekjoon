# 미로 탈출 명령어
# Greedy

def solution(n, m, x, y, r, c, k):
    answer = ''
    d = abs(r-x) + abs(c-y)
    if k < d or (k-d) % 2 != 0:
        return "impossible"
    
    md, mu, ml, mr = 0, 0, 0, 0

    if x < r:
        md = r-x
    else:
        mu = x-r
    if y < c:
        mr = c-y
    else:
        ml = y-c
    k -= d

    answer += 'd' * md
    x += md

    md = min(n - x, int(k/2))
    answer += 'd' * md
    mu += md
    k -= 2 * md

    answer += 'l' * ml
    y -= ml
    ml = min(y - 1, int(k/2))
    answer += 'l' * ml
    mr += ml
    k -= 2 * ml

    answer += 'rl' * int(k/2)
    answer += 'r' * mr
    answer += 'u' * mu

    dir = {}
    return answer