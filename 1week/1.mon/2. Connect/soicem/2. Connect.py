import math
result = 0
with open("connect.inp", 'r') as f:
    dots = [None for _ in range(3)]
    x1, y1, z1 = list(map(int, f.readline().split()))
    x2, y2, z2 = list(map(int, f.readline().split()))
    c1, c2, c3 = list(map(int, f.readline().split()))
    x21, y21, z21 = x2 - x1, y2 - y1, z2 - z1
    t = (-x1*x21 + c1 * x21 - y1 * y21 + c2 * y21 -z1 * z21 + c3 * z21) / (x21 * x21 + y21 * y21 + z21 * z21)
    x = (x2 - x1) * t + x1
    y = (y2 - y1) * t + y1
    z = (z2 - z1) * t + z1
    result = math.ceil((math.sqrt((c1 - x) * (c1 - x) + (c2 - y) * (c2 - y) + (c3 - z) * (c3 - z))))

with open("connect.out", 'w') as f:
    f.write(str(result))


