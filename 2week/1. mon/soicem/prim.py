class graph:
    def __init__(self):
        self.vertexList = set()
        self.edgeList = []
        self.weightList = {}
 
    def addVertex(self, vertex):
        self.vertexList.add(vertex)
 
    def addEdgeWeight(self, start, end, weight):
 
        self.edgeList.append((start, end))
        self.weightList[(start, end)] = weight
        # self.edgeList.append((end, start))
        # self.weightList[(end, start)] = weight
 
 
    def getAdjacecenyList(self):
        adjList = {}
        for vertex in self.vertexList: adjList[vertex] = []
        for edge in self.edgeList: adjList[edge[0]].append(edge[1])
        return adjList
 
    def dfs(self, start):
        current = start
        visitedList = []
        stack = [current]
        adjList = self.getAdjacecenyList()
 
        while stack:
            current = stack.pop()
            print(current)
            for adjVertex in adjList[current]:
                if adjVertex not in visitedList:
                    if adjVertex not in stack:
                        stack.append(adjVertex)
            visitedList.append(current)
        return visitedList
 
    def bfs(self, start):
        current = start
        visitedList = []
        queue = [current]
        adjList = self.getAdjacecenyList()
 
        while queue:
            current = queue.pop()
            print(current)
            for adjVertex in adjList[current]:
                if adjVertex not in visitedList:
                    if adjVertex not in queue:
                        queue.insert(0, adjVertex)
            visitedList.append(current)
        return visitedList
 
    def dijkstra(self, start, end):
        matrix = self.getMatrix(start)
        current = end
        shortestPath = []
        shortestPath.append(current)
        while current != start:
            current = matrix[current][0]
            shortestPath.append(current)
        shortestPath.reverse()
        return shortestPath
 
 
    def getMatrix(self, start):
        adjList = self.getAdjacecenyList()
        visitedList = []
        matrix = {}
        for vertex in self.vertexList: matrix[vertex] = (None, None)
        current = start
        while current != None:
            for adjNode in adjList[current]:
                if matrix[adjNode][0] == None:
                    if matrix[current][1] == None:
                        matrix[adjNode] = (current, self.weightList[(current, adjNode)])
                    else:
                        matrix[adjNode] = (current, matrix[current][1] +self.weightList[(current, adjNode)])
                elif matrix[adjNode][1] > matrix[current][1] + self.weightList[(current, adjNode)]:
                    matrix[adjNode] = (current, matrix[current][1] + self.weightList[(current, adjNode)])
 
            min = None
            visitedList.append(current)
 
            for vertex in self.vertexList:
 
                if vertex not in visitedList:
                    if matrix[vertex][0] !=None:
                        if min == None:
                            min = (vertex, matrix[vertex][1])
                        elif min[1] > matrix[vertex][1]:
                            min = (vertex, matrix[vertex][1])
 
            if min == None:
                current = min
            else:
                current = min[0]
        return matrix
 
    def prim(self, start):
        adjList = self.getAdjacecenyList()
        visitedList = [start]
        minSum = 0
        while len(visitedList) != len(self.vertexList):
            minNode = None
            for current in visitedList:
                for adjNode in adjList[current]:
                    if adjNode not in visitedList:
                        if minNode == None:
                            minNode = (adjNode, self.weightList[(current, adjNode)])
                        elif minNode[1] > self.weightList[(current, adjNode)]:
                            minNode = (adjNode, self.weightList[(current, adjNode)])
            visitedList.append(minNode[0])
            minSum += minNode[1]
 
        return minSum