import sys
sys.setrecursionlimit(10**9)

n, m, c = map(int, input().split())
arr = [[] for _ in range(n+1)]
for i in range(m):
    a,b, w = map(int,input().split())
    arr[a].append([b, f"{str(w)}"])
    arr[b].append([a, f"{str(w)}"])


ans = []
check = [0] * (n+1)

def dfs(node, string):
    if node >= n:
        tmp = sorted(map(int,string.split(" ")))
        ans.append(tmp)
        return
    else:
        for k in arr[node]:
            nt, nw = k
            if check[nt] == 0:
                check[nt] = 1
                dfs(nt, string +" "+ nw)
                check[nt] = 0

if __name__ == "__main__":
    # print(arr)
    check[1] = 1
    dfs(1, "0")
    cnt = 0
    for k in range(len(ans)):
        for j in range(len(ans[k])-1, -1, -1):
            ans[k][j] = 0
            cnt += 1
            if cnt >= c:
                break

    mi = 1e9
    # print(ans)
    for i in range(len(ans)):
        t = sum(ans[i])
        if mi > t:
            mi = t
    print(mi)

