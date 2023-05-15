# 두 원 사이의 정수 쌍
# Mathematics

import math

def solution(r1, r2):
    answer = 0
    for i in range(1, r2+1):
        b = math.floor(math.sqrt(r2*r2 - i*i))
        a, aa = 0, r1*r1 - i*i
        if aa > 0:
            a = math.ceil(math.sqrt(aa))
        answer += b-a+1
    answer *= 4
    return answer