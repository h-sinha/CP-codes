def solution(M, F):
    m, f = long(M), long(F)
    ans = 0
    while not (m == 1 and f == 1):
        if f <= 0 or m <= 0:
            return "impossible"
        if f == 1:
            return str(ans + m - 1)
        else:
            ans += long(m/f)
            m, f = f, m % f
    return str(ans)