from collections import deque
n, q = map(int,input().split())
n = 2 ** n
arr =[]
for i in range(n):
    arr.append(list(map(int,input().split())))
l_list = list(map(int,input().split()))

new = arr
dy = [0,0,1,-1]
dx = [1,-1,0,0]
check = [[0] * n for _ in range(n)]
count = [0] * (n+1)
cnt = 1

def rotate(L):
    global new
    jump_size = 2 ** L
    for y in range(0, n, jump_size):
        for x in range(0, n, jump_size):
            for i in range(jump_size):
                for j in range(jump_size):
                    new[y+j][x+jump_size - i - 1] = new[y+i][x+j]

def melt():

    global new
    for y in range(n):
        for x in range(n):
            c = 0
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if 0 <= ny < n and 0 <= nx < n:
                   if new[ny][nx] > 0:
                    c += 1
            if c < 3 and new[y][x] > 0:
                new[y][x] -= 1

def bfs(y,x, cnt):
    global check
    global new
    
    q = deque()
    q.append([y,x])
    ss = 0
    while q:
        cy , cx = q.popleft()
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if 0 <= ny < n and 0 <= nx < n:
                if new[ny][nx] > 0 and check[ny][nx] == 0:
                    check[ny][nx] = cnt
                    ss += 1
                    q.append([ny,nx])
    return ss
def sum():
    s = 0
    for y in range(n):
        for x in range(n):
            s += new[y][x]
    return s
if __name__ == "__main__":
    for i in l_list:
        rotate(i)
        melt()
    print(sum())
    for i in range(n):
        for j in range(n):
            if check[i][j] == 0 and new[i][j] > 0:
                count[cnt] += 1
                check[i][j] = cnt
                count[cnt] += bfs(i,j,cnt)
                cnt += 1
    print(max(count))

