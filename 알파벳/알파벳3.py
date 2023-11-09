import sys
input = sys.stdin.readline()
n, m = map(int, input.split())
arr = []
dy = [0, 0,-1, 1]
dx = [1,-1, 0, 0]
for i in range(n):
    arr.append(input)
check = [0] * 100
visited = [[0] * m for _ in range(n)]
ans = 0
mx = -1
check[ord(arr[0][0])] = 1

def dfs(y,x):
    global mx, ans, check, visited
    if visited[y][x] == 1:
        return
    visited[y][x] = 1
    check[ord(arr[y][x])] = 1
    if ans > mx:
        mx = ans
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny == 0 and nx == 0: continue
        if 0 <= ny < n and 0 <= nx < m :
            if visited[ny][nx] == 0 :
                if check[ord(arr[ny][nx])] == 0:


                    ans += 1
                    dfs(ny, nx)
                    visited[ny][nx] = 0
                    check[ord(arr[ny][nx])] = 0
                    ans -= 1
ans += 1

dfs(0,0)

print(mx)