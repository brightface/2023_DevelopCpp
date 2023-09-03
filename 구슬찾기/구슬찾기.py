from collections import deque
n,r = map(int,input().split())
check = [0] * (n+1)
rcheck= [0] * (n+1)
arr = [[] for _ in range(n+1)]
rarr = [[] for _ in range(n+1)]
def bfs(k):
    global check
    cnt = 0
    q = deque()
    q.append(k)
    check[k] = 1
    while q:
        cur = q.popleft()
        for next in arr[cur]:
            if check[next] == 0:
                check[next] = 1
                cnt += 1
                q.append(next)
    return cnt
def rbfs(k):
    global rcheck
    q = deque()
    q.append(k)
    cnt = 0
    while q:
        cur = q.popleft()
        for next in rarr[cur]:
            if rcheck[next] == 0:
                rcheck[next] = 1
                cnt += 1
                q.append(next)
    return cnt

if __name__ == "__main__":
    for i in range(r):
        a,b = map(int,input().split())
        arr[a].append(b)
        rarr[b].append(a)

    mx = (n+1)//2
    ans = 0
    for i in range(1, n+1):
        check = [0] * (n+1)
        rcheck = [0] * (n+1)
        cnt = bfs(i)
        rcnt = rbfs(i)
        # mx 보다 크면 안돼
        if cnt >= mx or rcnt >= mx:
            ans += 1
    print(ans)
