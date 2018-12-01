import bisect
n = int(input())
a = list()
arr = raw_input().split(' ')
a = [int(num) for num in arr]
for i in range(1,n):
	a[i] = a[i-1] + a[i]
m = int(input())
q = list()
arr = raw_input().split(' ')
q = [int(num) for num in arr]
for i in range(0,m):
	i = bisect.bisect_left(a,q[i])
	print(i+1)