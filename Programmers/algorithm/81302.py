# 거리두기 확인하기
# Implementation

def solution(places):
    answer = []
    dm = [[0,-1],[0,1],[1,0],[-1,0]]
    dm2 = [[0,-2], [0,2], [2,0], [-2,0]]
    dm3 = [[1,1], [1,-1], [-1,1], [-1,-1]]
    for place in places:
        flag = True
        for y in range(0,5):
            for x in range(0,5):
                if place[y][x] == 'P':
                    for k in range(0,4):
                        ny, nx = y + dm[k][0], x + dm[k][1]
                        if ny >= 0 and nx >= 0 and ny < 5 and nx < 5:
                            if place[ny][nx] == 'P':
                                flag = False
                                break

                    for k in range(0,4):
                        ny, nx = y + dm2[k][0], x + dm2[k][1]
                        if ny >= 0 and nx >= 0 and ny < 5 and nx < 5:
                            if place[ny][nx] == 'P' and place[y+dm[k][0]][x+dm[k][1]] == 'O':
                                flag = False
                                break

                    for k in range(0,4):
                        ny, nx = y + dm3[k][0], x + dm3[k][1]
                        if ny >= 0 and nx >= 0 and ny < 5 and nx < 5:
                            if place[ny][nx] == 'P' and (place[ny][x] == 'O' or place[y][nx] == 'O'):
                                flag = False
                                break

            if flag == False:
                break
        if flag:
            answer.append(1)
        else:
            answer.append(0)
    return answer
