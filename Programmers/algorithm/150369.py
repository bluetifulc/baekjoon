# 택배 배달과 수거하기
# Greedy
def solution(cap, n, deliveries, pickups):
    answer = 0

    cur_d = 0
    cur_p = 0

    for i in range(n-1, -1, -1):
        time = 0

        cur_d -= deliveries[i]
        cur_p -= pickups[i]

        while cur_d < 0 or cur_p < 0:
            cur_d += cap
            cur_p += cap
            time += 1

        answer += time * (i+1) * 2

    return answer