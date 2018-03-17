import timeit
start = timeit.default_timer()

from itertools import combinations
#C:\\Users\\shawn\\Documents\\coding_practice\\algo_prac\\alwork 01 Square\\square1.inp
f = open('square1.inp','r')

how_many = int(f.readline())
indata = tuple(sorted(list(map(int, f.readline().split(' ')))))
squaredata = tuple(map(lambda a: a**2, indata[:how_many-1]))
result = list()
f.close()

for x in range(2,how_many):
	if indata[x]<=squaredata[1]:	continue
	combilist = map(lambda a:a[0]+a[1], list(combinations(squaredata[:x],2)))
	if indata[x] in combilist:	result.append(indata[x])
	
print(result)

stop = timeit.default_timer()
print("실행시간 : ", stop - start)