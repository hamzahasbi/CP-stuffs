MAX = 10**9 + 7

n = int(input())

dp = [0] * n

dp[0] = 1

for i in range(min(6, n)):
    dp[i] = 2**i

for i in range(6, n):
    for j in range(1, 7):
        dp[i] += dp[i - j] % MAX

print(dp[-1] % MAX)
