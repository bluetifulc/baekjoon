# 행운의 문자열
# String

word = input().rstrip()
counter = dict()

for letter in word:
    if letter not in counter:
        counter[letter] = 1
        continue
    counter[letter] += 1

def dfs(pre, idx):
    if(idx == len(word)):
        return 1
    result = 0
    for key in counter.keys():
        if pre == key or counter[key] == 0:
            continue
        counter[key] -= 1
        result += dfs(key, idx+1)
        counter[key] += 1
    return result

print(dfs('', 0))