k,b,n,t = input().split(' ')
pre = []
for i in range (1000001):
	pre[i] = pre[i-1]*k
