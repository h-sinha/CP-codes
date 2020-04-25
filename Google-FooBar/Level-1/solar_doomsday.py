from bisect import bisect

def solution(n):
	ans = []
	squares = [x*x for x in range(1000)]
	while n > 0:
		it = bisect(squares, n)
		ans.append(squares[it-1])
		n -= squares[it - 1]
	return ans

