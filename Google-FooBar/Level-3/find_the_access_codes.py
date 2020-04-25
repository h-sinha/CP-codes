def solution(l):
    # Your code here
    n = len(l)
    dp = [0]*n
    for i in range(n):
    	for j in range(i+1,n):
    		if l[j] % l[i] == 0:
    			dp[i] += 1
    ans = 0
    for i in range(n):
    	for j in range(i+1, n):
    		if l[j] % l[i] == 0:
    			ans += dp[j]
    return ans