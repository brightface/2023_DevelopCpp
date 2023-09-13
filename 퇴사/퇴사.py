n = int(input())
dp = [0] * (n+1) # n시간만큼의 갔을때의 최대값.
weight = [] 
time =[] 

for i in range(1, n+1):
    a, b= map(int,input().split())
    weight.append(b)
    time.append(a)

for i in range(n-1, -1, -1): # 뒤에서부터 거꾸로
    if time[i] + i > n: # 상담에 필요한 일수가 퇴사일을 넘어가면
        dp[i] = dp[i+1] # 다음날 값 그대로 가져옴
    else:
        dp[i] = max(dp[i+1], dp[time[i] + i] + weight[i]) # 오늘 상담을 안 할 경우와 상담을 할 경우 중 max 값

print(dp[0])
# print(dp[n])
# print(dp)
# for i in range(1, n+1):
#     flag = 1
#     for j in range(save_idx, save_idx + time[i]):
#         if dp[save_idx] < weight[j]:
#             flag = 0
#             for k in range(j)
#             save_idx = j
#             break
#             # dp[j] = weight[j]
            
    
