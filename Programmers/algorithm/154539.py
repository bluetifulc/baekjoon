# 뒤에 있는 큰 수 찾기
# Stack

def solution(numbers):
    answer = []
    st = []
    numbers.reverse()
    for number in numbers:
        while st and st[-1] <= number:
            st.pop()
        if not st:
            answer.append(-1)
        else:
            answer.append(st[-1])
        st.append(number)
    answer.reverse()

    return answer