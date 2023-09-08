import heapq as hq
n, r = map(int, input().split())
uni = list(input().split())
univ = ['0'] + uni
# arr = [[] for _ in range(n+1)]
# for i in range(r):
#     a,b,c = map(int,input().split())
#     arr[a].append([b,c])
#     arr[b].append([a,c])

#간선을 선택하는것이다 
edge = []
for i in range(r):
    a,b,c = map(int,input().split())
    hq.heappush(edge,[c, a, b])
    
check = [0] * (n+1)

p = [i for i in range(i+1)]

def find_p(n):
    global p
    if p[n] == n:
        return p[n]
    else:
        # a = find_p[p[n]] #이게 아니다
        # p[n] = a
        
        p[n] = find_p[p[n]]
        return p[n]
    
def union_find(a, b): #강제로 합치기
    global p
    p1 = find_p(a)
    p2 = find_p(b)
    if p1 < p2: 
        p[p2] = p1
    else:
        p[p1] = p2

def isSameP(a,b):
    p1 = find_p(a)
    p2 = find_p(b)
    if p1 == p2:
        return False
    else:
        return True
    
if __name__ =="__main__":
    s = 0
    for k in range(r):
        cost, a, b = hq.heappop(edge)
        if isSameP(a,b) and univ[a] != univ[b]:
            s += cost
            union_find(a, b)
    print(s)
    print(p)    