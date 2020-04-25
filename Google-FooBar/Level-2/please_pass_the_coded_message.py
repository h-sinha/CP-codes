import numpy as np

def solution(l):
	n = len(l)
	sl = sorted(l, reverse = True)
	modl = [x%3 for x in sl]
	sum = np.sum(modl)
	rem = sum % 3
	if sum == 0:
		return ''.join(str(x) for x in sl)
	for i in range(n-1, 0, -1):
		if modl[i] == rem:
			return ''.join(str(x) for j,x in enumerate(sl) if j != i)
	rem = 3 - rem
	for i in range(n-1, 0, -1):
		if len(idx) >= 2:
			break
		if modl[i] == rem:
			idx.append(i)
	if len(idx) < 2:
		return 0
	return ''.join(str(x) for j,x in enumerate(sl) if j not in idx)
