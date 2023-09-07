from collections import deque
n = int(input())
city = int(input())

arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))

#change from arr to ad_arr
ad_arr = [ [] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            ad_arr[i].append(j)
            ad_arr[j].append(i)

parents = [0] * (n)
check = [0] * (n)

def bfs(p, n):
    global check,parents
    check[n] = 1
    q = deque()
    q.append(n)
    while q:
        c = q.popleft()
        for nxt in ad_arr[c]:
            if check[nxt] == 0:
                check[nxt] = 1
                parents[nxt] = p

if __name__ == "__main__":
    plan = list(map(int,input().split()))
    for i in plan:
        if check[i-1] == 0:
            bfs(i-1, i-1)
    flag = 0
    for p in parents:
        if p != 0:
            flag = 1
            break
    if not flag:
        print("YES")
    else:
        print("NO")

    # print(parents)

#
#
# def find_parent(n):
#     if parents[n] == n:
#         return
#     else:
#         parents[n] = arr[]
#

