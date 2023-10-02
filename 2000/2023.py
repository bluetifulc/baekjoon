# 신기한 소수
# Prime, Back-Tracking
import sys
from math import sqrt
input = sys.stdin.readline

n = int(input())
m = 10 ** (n-1)

def is_prime(num):
    if not num % 2:
        return False
    c = int(sqrt(num))
    for i in range(3, c+1, 2):
        if not num % i:
            return False
    return True

def dfs(num):
    if num >= m:
        print(num)
        return
    for i in range(1,10,2):
        t = num * 10 + i
        if is_prime(t):
            dfs(t)

dfs(2)
dfs(3)
dfs(5)
dfs(7)