s = input().strip()
mod = 301907
n = len(s)
dp = [[0] * (n + 1) for _ in range(n + 1)]
dp[0][0] = 1

for i in range(n):
    for bal in range(n):
        if dp[i][bal] == 0:
            continue
        if s[i] == '(' or s[i] == '?':
            dp[i + 1][bal + 1] = (dp[i + 1][bal + 1] + dp[i][bal]) % mod
        if s[i] == ')' or s[i] == '?':
            if bal > 0:
                dp[i + 1][bal - 1] = (dp[i + 1][bal - 1] + dp[i][bal]) % mod

print(dp[n][0])
