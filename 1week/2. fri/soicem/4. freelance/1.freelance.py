import math
import sys

rl = lambda:sys.stdin.readline().strip()

def letsWorks(tasks):
    result = []
    print(tasks)
    for i in range(len(tasks)):
        result.append(working(tasks[i], tasks[0:i] + tasks[i+1:]))
        result[i][1] += 10
    minVal = None
    for task in result:
        if minVal == None:
            minVal = task
        elif task[1] * minVal[0] > minVal[1] * task[0]:
            minVal = task
        elif task[1] * minVal[0] == minVal[1] * task[0]:
            if task[0] < minVal[0]:
                minVal = task
    return minVal

def working(task, tasks):
    minTup = [0, 0]
    for i in range(len(tasks)):

        if tasks[i][0] > task[1]:
            ret = working(tasks[i], tasks[0:i] + tasks[i + 1:])
            if ret is not None:
                if minTup[0] == 0:
                    minTup = ret
                elif(minTup[1] * ret[0] > ret[1] * minTup[0]):
                    minTup = ret
    #print("min : ", minTup, task[1], task[0])

    return [minTup[0] + task[1] - task[0] + 1, minTup[1] + task[2] - (10)]

with open("freelance.inp", 'r') as f:
    dots = [None for _ in range(3)]
    n = int(f.readline())
    works = []
    for i in range(n):
        works.append(list(map(int, f.readline().split())))

    print(letsWorks(works))
    with open("freelance.out", 'w') as fw:
        fw.write(' '.join([str(val) for val in letsWorks(works)]))



