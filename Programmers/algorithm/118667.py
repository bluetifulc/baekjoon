# 두 큐 합 같게 만들기
# Sliding-Window, Tow-pointer

def solution(queue1, queue2):
    q = queue1 + queue2
    a = sum(queue1)
    b = sum(queue2)
    answer = 0
    lo, hi = 0, len(queue1)-1
    while lo < hi:
        if a == b:
            break
        if a > b:
            a -= q[lo]
            b += q[lo]
            lo = lo+1
        else:
            hi = hi+1
            if hi >= len(q):
                break
            b -= q[hi]
            a += q[hi]
        answer += 1
    if a != b:
        answer = -1
    return answer