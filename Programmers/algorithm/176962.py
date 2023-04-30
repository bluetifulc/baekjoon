# 과제 진행하기
# Stack

def solution(plans):
    plans.sort(key = lambda x: x[1])
    answer = []
    st = []
    last = 0
    for name, start, time in plans:
        h, m = map(int, start.split(':'))
        time = int(time)
        s = 60*h + m
        remain = s - last
        while st and remain > 0:
            prev_name, prev_time = st.pop()
            if prev_time > remain:
                st.append((prev_name, prev_time - remain))
                break
            answer.append(prev_name)
            remain -= prev_time

        st.append((name, time))
        last = s
    st.reverse()
    answer.extend([name for name, _ in st])
    return answer