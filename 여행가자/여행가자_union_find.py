n = int(input())
r = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))
plan = list(map(int,input().split()))
p = [k for k in range(n)]
def find_p(a):
    if p[a] == a:
        return p[a]
    else:
        p[a] = find_p(p[a])
        return p[a]

def union(a, b):
    p1 = find_p(a)
    p2 = find_p(b)

    if p1 > p2: # p2 가 더작음
        p[p1] = p2
    else:
        p[p2] = p1

if __name__ =="__main__":
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 1:
                union(i, j)
                union(j, i)


    flag = 1
    if len(plan) >= 1:
        tmp = p[plan[0]-1]
        for k in range(len(plan)):
            if tmp != p[plan[k]-1]:
                flag = 0
                break
    if flag:
        print("YES")
    else:
        print("NO")