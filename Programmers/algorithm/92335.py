# k진수에서 소수 개수 구하기
# prime
import math
def check(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def convert(n, k):
    result = ''
    while n:
        result = result + str(n % k)
        n //= k
    result = result[::-1]
    return result

def solution(n, k):
    answer = 0
    s = convert(n, k)
    s_list = s.split('0')
    for ss in s_list:
        if ss == '' or ss == '1':
            continue
        ss = int(ss)
        if check(ss):
            answer += 1
    return answer

print(solution(437674, 3))