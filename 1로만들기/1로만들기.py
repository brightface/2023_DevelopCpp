from collections import deque
n = int(input())
dp = [1000001] * (n+1)
# s = [str(n)] * (n+1)
s = [[] for _ in range(n+1)]
s[n] = str(n)
dp[n] = 0
q = deque()
q.append(n)
while q:
    i = q.popleft()
    if i == 1:
        break

    if i % 3 == 0:
        if i//3 >= 0:
            if dp[i//3] > dp[i] + 1:
                dp[i//3] = dp[i] + 1
                s[i//3] = s[i] + " " + str(i//3)
                q.append(i//3)

    if i % 2 == 0:
        if i // 2 >= 0:
            if dp[i//2] > dp[i] + 1:
                dp[i//2] = dp[i] + 1
                s[i//2] = s[i] + " " + str(i//2)
                q.append(i // 2)


    if i-1 > 0:
        if dp[i-1] > dp[i] + 1:
            dp[i-1] = dp[i] + 1
            s[i-1] = s[i] +  " " + str(i-1)
            q.append(i-1)
    a = 1
print(dp[1])
print(s[1])
# print(s)