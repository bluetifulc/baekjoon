# 두 배열의 합
# Brute-force, Counter(hash)
import sys
from collections import Counter
input = sys.stdin.readline

t = int(input())
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

answer = 0
c = Counter()

for i in range(n):
    for j in range(i, n):
        c[sum(a[i:j+1])] += 1

for i in range(m):
    for j in range(i, m):
        answer += c[t - sum(b[i:j+1])]

print(answer)