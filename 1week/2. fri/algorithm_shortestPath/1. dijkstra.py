import sys
rl = lambda:sys.stdin.readline().strip()

v, e = list(map(int, rl().split()))
start = int(rl())
weightList = {}
adjList = {}
visitedList = []
for i in range(1, v + 1):
    adjList[i] = []

for _ in range(e):
    v1, v2, weight = list(map(int, rl().split()))
    adjList[v1].append(v2)
    weightList[(v1, v2)] = weight

shortestMatrix = {}
for i in range(1, v + 1):
    shortestMatrix[i] = None

n = start
for _ in range(v):
    visitedList.append(start)
    for vn in adjList[n]:
        if shortestMatrix[vn] == None:
            if shortestMatrix[n] == None:
                shortestMatrix[vn] = (n, weightList[(n, vn)] )
            else:
                shortestMatrix[vn] = (n, weightList[(n, vn)] + shortestMatrix[n][1])
        else:
            if shortestMatrix[vn][1] > weightList[(n, vn)] + shortestMatrix[n][1]:
                shortestMatrix[vn] = (n, weightList(n, vn) + shortestMatrix[n][1])
    n = None
    for i in range(1, v):
        if i not in visitedList:
            if shortestMatrix[i] is not None:
                if n is None:
                    n = i
                elif shortestMatrix[n][1] > shortestMatrix[i][1]:
                    n = i

for i in range(1, v + 1):
    if i == start:
        print(0)
    elif shortestMatrix[i] == None:
        print('INF')
    else:
        print(shortestMatrix[i][1])