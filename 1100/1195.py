# 킥다운
# Brute-Force

import sys
input = sys.stdin.readline

def check(c):
    while c:
        if (c % 10) == 4:
            return False
        c //= 10
    return True

a, b = int(input()), int(input())

result = 300
ta, tb = a, b
for _ in range(len(str(a))+1):
    if check(ta + tb):
        result = min(result, len(str(ta + tb)))
    tb *= 10

ta, tb = a, b
for _ in range(len(str(b))+1):
    if check(ta + tb):
        result = min(result, len(str(ta + tb)))
    ta *= 10

print(result)