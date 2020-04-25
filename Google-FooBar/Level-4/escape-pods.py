class Escape:
	def __init__(self, entrances, exits, path):
		self.n = len(path[0]) + 2
		self.graph = list([0]*self.n for _ in range(self.n))
		for x in entrances:
			self.graph[0][x+1] = 10000000
		for x in exits:
			self.graph[x+1][self.n - 1] = 10000000
		for i in range(self.n - 2):
			for j in range(self.n - 2):
				self.graph[i+1][j+1] = path[i][j]
		self.rgraph = self.graph
		self.max_flow = 0

	def bfs(self, parent):
		visit = [0]*self.n
		q = [0]
		visit[0] = 1
		parent[0] = -1

		while len(q) > 0:
			cur = q[0]
			q.pop(0)
			for i in range(self.n):
				if visit[i] == 0 and self.rgraph[cur][i] > 0:
					q.append(i)
					parent[i] = cur
					visit[i] = 1
		return visit[self.n - 1] == 1

	def fordFulkerson(self):
		parent = [0] * self.n
		while self.bfs(parent):
 			cur = self.n - 1
 			flow = 1000000
 			while cur != 0:
 				flow = min(flow, self.rgraph[parent[cur]][cur])
 				cur = parent[cur]

 			cur = self.n - 1
 			while cur != 0:
 				self.graph[parent[cur]][cur] -= flow
 				self.graph[cur][parent[cur]] += flow
 				cur = parent[cur]

 			self.max_flow += flow
		return


def solution(entrances, exits, path):
	escape = Escape(entrances, exits, path)
	escape.fordFulkerson()
	return escape.max_flow
