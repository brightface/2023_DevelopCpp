'''
3
3
ENTJ INTP ESFJ
4
ESFP ESFP ESFP ESFP
5
INFP INFP ESTP ESTJ ISTJ
'''
from itertools import combinations
testCases = int(input())
for _ in range(testCases):
    n = int(input())
    if n >= 32:
        print(0)
        arr = list(input().split())
    else:
        arr = list(input().split())
        mx = 1e10
        for l in combinations(arr, 3):
            l1, l2, l3 = l
            s = 0
            for i in range(4):
                if l1[i] != l2[i]:
                    s += 1
                if l2[i] != l3[i]:
                    s += 1
                if l3[i] != l1[i]:
                    s += 1
            if s < mx:
                mx = s
        print(mx)
