from itertools import combinations
n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))
s = set(i for i in range(1, n+1))
mi = 1e9
for ar in combinations(s, n//2):
    ar = set(ar)
    # print(ar, s-ar, end =' ')
    s1 = 0
    for t in combinations(ar, 2):
        a1, a2 = t
        # print(a1, a2)
        a1 -=1
        a2 -=1
        s1 += arr[a1][a2]
        s1 += arr[a2][a1]
    s2 = 0
    for t in combinations(s-ar, 2):
        a1, a2 = t
        # print(a1, a2)
        a1 -= 1
        a2 -= 1
        s2 += arr[a1][a2]
        s2 += arr[a2][a1]
    # print(s1, s2, "score")
    tmp = abs(s1 - s2)
    if tmp < mi:
        mi = tmp
print(mi)
