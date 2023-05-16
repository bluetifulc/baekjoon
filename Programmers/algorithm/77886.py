# 110 옮기기
# Greedy

def solution(s):
    answers = []
    for a in s:
        answer = []
        one = 0
        x = 0
        for aa in a:
            if aa == '1':
                one += 1
                continue
            if aa == '0':
                if one >= 2:
                    one -= 2
                    x += 1
                else:
                    if one == 1:
                        one -= 1
                        answer.append(1)
                    answer.append(0)
        for i in range(x):
            answer.append(1)
            answer.append(1)
            answer.append(0)
        for i in range(one):
            answer.append(1)
        answers.append(''.join(map(str, answer)))
    return answers