n, m = map(int,input().split())
arr = []
dy = [0, 0,-1, 1]
dx = [1,-1, 0, 0]

for i in range(n):
    arr.append(input())
# print(arr)
check = [[0] * (m+1) for _ in range(n+1)]
ans = 0
mx = -1
road = set()
c = ""
# road.add(c)
def dfs(y, x, nc):
    global ans, check, d, mx, road
    print("1")
    if check[y][x] == 1:
        print("2")
        return
    else:
        print("3")
        #dfs 로 넘어 왔을때 - d에 있으면 가면 안돼
        # print(arr[y][x], d[arr[y][x]])
        if nc in road:
            print("4")
            return
        else: #road 에 c 없고 check가 0 이야.
            if check[y][x] == 0:
                print("5")
                check[y][x] = 1
                nc += arr[y][x]
                road.add(nc)
                print(road)
                ans += 1
                if mx < ans:
                    mx = ans
                for i in range(4):
                    print("6")
                    ny = y + dy[i]
                    nx = x + dx[i]
                    nnc = nc + arr[ny][nx]
                    print(nnc)
                    if 0 <= ny < n and 0 <= nx < m and not (ny == 0 and nx == 0):

                        if not nnc in road and check[ny][nx] == 0:
                            print("7")
                            road.add(nnc)
                            print(road)
                            dfs(ny, nx, nnc)
                    road.remove(nnc)
                    print(road)
                    check[ny][nx] = 0
                    ans -= 1
#
dfs(0,0, "")
# print(d)
print(mx)
