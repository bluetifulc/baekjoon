import math
# 점 찍기
# mathematics

def solution(k, d):
    answer = 0
    for x in range(0, d+1, k):
        y = math.floor(math.sqrt(d**2 - x**2))
        answer += y // k + 1
    return answer

print(solution(2,4))