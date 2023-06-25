# 풍선 터트리기
# Greedy

def solution(a):
    answer = 0
    mini = min(a)
    mini2 = 1000000001
    for t in a:
        if t == mini:
            answer += 1
            break
        if t < mini2:
            answer += 1
            mini2 = t
    mini2 = 1000000001
    a.reverse()
    for t in a:
        if t == mini:
            break
        if t < mini2:
            answer += 1
            mini2 = t

    return answer