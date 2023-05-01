# 표현 가능한 이진트리
# Tree

def solve(number, prev):
    global flag
    mid = len(number) // 2
    if number[mid] == '1' and prev == '0':
        flag = True
        return
    if len(number) > 1:
        solve(number[:mid], number[mid])
        solve(number[mid+1:], number[mid])


def solution(numbers):
    answer = []
    for number in numbers:
        global flag
        flag = False
        number = format(number, 'b')

        i = 1
        tree_size = 0
        while True:
            if pow(2, i)-1 >= len(number):
                tree_size = pow(2,i)-1
                break
            i += 1
        number = '0'*(tree_size - len(number))+number
        
        solve(number, 1)

        if flag:
            answer.append(0)
        else:
            answer.append(1)
    return answer