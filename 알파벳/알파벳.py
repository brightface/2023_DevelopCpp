n, m = map(int,input().split())
arr = []
dy = [0, 0,-1, 1]
dx = [1,-1, 0, 0]
d = {}

cnt = 65

for i in range(65, 65+26):
    d[chr(i)] = 0
# print(d)
for i in range(n):
    arr.append(input())
# print(arr)
check = [[0] * (m+1) for _ in range(n+1)]
ans = 0
mx = -1
def dfs(y, x):
    global ans, check, d, mx
    if check[y][x] == 1 :
        return
    else:
        #dfs 로 넘어 왔을때 - d에 있으면 가면 안돼
        # print(arr[y][x], d[arr[y][x]])
        if d[arr[y][x]] == 1:
            return
        else: #둘다 0이야.
            if check[y][x] == 0:
                check[y][x] = 1
                d[arr[y][x]] = 1
                ans += 1
                if mx < ans:
                    mx = ans
                for i in range(4):
                    ny = y + dy[i]
                    nx = x + dx[i]
                    if 0 <= ny < n and 0 <= nx < m and not (ny == 0 and nx == 0):
                        if d[arr[ny][nx]] == 0 and check[ny][nx] == 0:
                            dfs(ny, nx)
                            d[arr[ny][nx]] = 0
                            check[ny][nx] = 0
                            ans -= 1
#
dfs(0,0)
# print(d)
print(mx)
