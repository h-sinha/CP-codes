class Game:
	def __init__(self, banana_list):
		self.n = len(banana_list)
		self.graph = list([0]*self.n for _ in range(self.n))
		for i in range(self.n):
			for j in range(i+1, self.n):
				if self.infinite(banana_list[i], banana_list[j]):
					self.graph[i][j] = 1
					self.graph[j][i] = 1
		self.max_match = self.max_bpm()

	def gcd(self, x, y):
		if y == 0:
			return x
		return self.gcd(y, x % y)

	def infinite(self, x, y):
		if x == y:
			return 0
		g = self.gcd(x, y)
		if (x+y) % 2 == 1:
			return 1
		x /= g
		y /= g
		x, y = max(x,y), min(x,y)    
		return self.infinite(x - y, 2*y)
	
	def bpm(self, u, match, visited):
		for i in range(self.n):
			if self.graph[u][i] and visited[i] == 0:
				visited[i] = 1
				if match[i] == -1 or self.bpm(match[i], match, visited):
					match[i] = u
					return 1
		return 0

	def max_bpm(self):
		match = [-1]*self.n
		ans = 0
		for i in range(self.n):
			visited = [0]*self.n
			if self.bpm(i, match, visited):
				ans += 1
		return self.n - 2*(ans//2)

def solution(banana_list):
	game = Game(banana_list)
	return game.max_match

