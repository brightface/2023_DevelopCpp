class Person:
    def __init__(self, x,y,road, sum):
        self.x = x
        self.y = y
        self.road = road
        self.sum = sum
def rotate(sy, sx, ey, ex):
    global arr
    ay, ax = -1, -1
    by, bx = -1, -1
    if sy < ey:
        by = ey
        ay = sy
    else:
        ay = sy
        by = ey

    if sx < ex:
        bx = ex
        ax = sx
    else:
        ax = ex
        bx = sx
    #반드시 정사각형 이어야 하며 정사각형을 잘 골라야한다.
    new_arr = [[0] * (bx - ax) for _ in range(by - ay)]
    for i in range(ay, by):
        for j in range(ax, ax):
            new_arr[i][j] = arr[by - 1 - j][i] #by 가 핵심이다.


