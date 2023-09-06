'''
리스트에 각 아기상어들의 좌표를 저장한다.
그후 각 아기 상어들의 좌표에 따른
bfs를 돌고난후 각 상어의 거리 값들을 통해 최대값을 찾아 낸다.
'''
from collections import deque

n, m = map(int,input().split())
arr = []
sharks = []

dy = [0,0,1,-1,1,1,-1,-1]
dx = [1,-1,0,0,1,-1,1,-1]
for i in range(n):
    arr.append(list(map(int,input().split())))

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            sharks.append([i,j])

check = [[[0] * m for _ in range(n)] for _ in range(len(sharks))]

def bfs(y,x,i):
    global check
    q = deque()
    q.append([y,x,0])
    check[i][y][x] = 1
    while q:
        cy, cx ,cn = q.popleft()
        for w in range(8):
            ny = cy + dy[w]
            nx = cx + dx[w]
            nn = cn + 1
            if 0 <= ny < n and 0 <= nx < m :
                if check[i][ny][nx] == 0:
                    check[i][ny][nx] = nn
                    q.append([ny,nx,nn])
                # elif check[i][ny][nx] != 0 and check[i][ny][nx] > nn:
                #     check[i][ny][nx] = nn
                #     q.append([ny,nx, nn])


if __name__ == "__main__":
    # print(check)
    for i, ar in enumerate(sharks):
        y, x = ar
        bfs(y,x, i)

    ans = [[0] * m for _ in range(n)]
    for j in range(n):
        for k in range(m):
            tmp = check[0][j][k]
            for i in range(len(sharks)):
                if check[i][j][k] < tmp:
                    tmp = check[i][j][k]
            ans[j][k] = tmp
    k = -1
    for t in ans:
        if k < max(t):
            k = max(t)
    print(k)
