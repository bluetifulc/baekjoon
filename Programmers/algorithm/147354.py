# 테이블 해시 함수
# Sort

def solution(data, col, row_begin, row_end):
    answer = 0
    data.sort(key = lambda x: (x[col-1], -x[0]))
    for i in range(row_begin, row_end+1):
        tmp = 0
        for e in data[i-1]:
            tmp += e % i
        answer ^= tmp
    return answer