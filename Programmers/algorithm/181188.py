# 요격 시스템
# Greedy

def solution(targets):
    targets = sorted(targets, key=lambda a: a[1])
    answer = 0
    cur_end = -1
    for target in targets:
        if target[0] < cur_end and target[1] >= cur_end:
            continue
        cur_end = target[1]
        answer += 1

    return answer


print(solution([[4,5],[4,8],[10,14],[11,13],[5,12],[3,7],[1,4]]))