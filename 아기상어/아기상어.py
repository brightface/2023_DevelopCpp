from collections import deque
n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

baby_shark = 2
check = [[0] * n for _ in range(n)]
dy = [0,0,1,-1]
dx = [1,-1,0,0]
b_y = -1
b_x = -1

time = 0
def find_baby():
    global arr, b_y, b_x
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 9:
                b_y = i
                b_x = j
                return
def find_fish():
    global arr
    for i in range(n):
        for j in range(n):
            if 1<= arr[i][j] <= 6:
                return True
    return False
dr = ["r","l","d","u"]
def bfs(y,x): #start 상어
    global check
    q = deque()
    q.append([y, x, baby_shark, 1, ""])
    check[y][x] = 1
    while q:
        cy, cx, cshark, cc, croad = q.popleft()
        #오른쪽 , 왼쪽, 아래, 위
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            nc = cc + 1
            nroad = croad + dr[i]
            if 0 <= ny < n and 0 <= nx < n and check[ny][nx] == 0 and arr[ny][nx] < cshark:
                q.append([ny, nx, cshark, nc, nroad])
                check[ny][nx] = nc
def eat():
    mi = 1e9
    global check, arr, b_y, b_x, baby_shark, time

    #mi 찾기
    for i in range(n):
        for j in range(n):
            if check[i][j] != 0 and 1 <= arr[i][j] and arr[i][j] <= 6 and i != b_y and j != b_x:
                if mi > check[i][j]:
                    mi = check[i][j]
    m_arr = []
    #mi 좌표 찾기
    for i in range(n):
        for j in range(n):
            if check[i][j] == mi and 1 <= arr[i][j] <= 6:
                m_arr.append([i,j])
    m_arr = sorted(m_arr, key = lambda x: (x[0], -x[1]))

    if len(m_arr) == 0:
        print(time)
        exit(0)
    else:
        my, mx = m_arr[0]
        #이동후 크기 증가
        arr[my][mx] = 9
        arr[b_y][b_x] = 0
        baby_shark += 1
        time += mi-1
        check = [[0] * n for _ in range(n)]
    # m_arr.sort(key = s_key(m_arr), reverse = True)

# def s_key(arr):
#     return arr[0]

if __name__ == "__main__":

    while find_fish():
        find_baby()
        bfs(b_y, b_x)
        eat()
    print(time)


