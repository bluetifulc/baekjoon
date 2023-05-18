# 광물 캐기
# Greedy

def solution(picks, minerals):
    chunks = []
    answer = 0
    m = {
        'diamond': 0,
        'iron': 1,
        'stone': 2
    }
    costs = [[1,1,1], [5,1,1], [25,5,1]]
    a = sum(picks)
    minerals = minerals[:a*5]
    minerals = [m[mineral] for mineral in minerals]
    
    for i in range(0, len(minerals), 5):
        cost = 0
        tmp = []
        for j in range(5):
            if i + j >= len(minerals):
                break
            tmp.append(minerals[i+j])
            cost += costs[2][minerals[i+j]]
        chunks.append((cost, tmp))
    chunks.sort(key=lambda x: -x[0])
    
    for chunk in chunks:
        pick = -1
        for i in range(3):
            if picks[i] >= 1:
                pick = i
                break
        if pick == -1:
            break
        picks[pick] -= 1
        for mineral in chunk[1]:
            answer += costs[pick][mineral]

    return answer
