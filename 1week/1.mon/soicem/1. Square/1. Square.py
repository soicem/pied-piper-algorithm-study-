result = []
with open("square.inp", 'r') as f:
    n = int(f.readline())
    xk = list(map(int, f.readline().split()))
    t = 0
    while t < len(xk):
        i = t + 1
        while i < len(xk):
            v2 = xk[t] * xk[t]
            if (v2 + xk[i] * xk[i]) in xk:
                result.append(str(v2 + xk[i] * xk[i]))
            i += 1
        t += 1
with open("square.out", 'w') as f:
    print(result)
    f.write(' '.join(result))

