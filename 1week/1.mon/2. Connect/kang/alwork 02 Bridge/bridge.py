import timeit
start = timeit.default_timer()
#C:\\Users\\shawn\\Documents\\coding_practice\\algo_prac\\alwork 02 Bridge\\connect1.inp
f = open('connect1.inp','r')
A = list(map(int,f.readline().split(' ')))	#선분의 한 끝
B = list(map(int,f.readline().split(' ')))	#선분의 다른 한 끝
P = list(map(int,f.readline().split(' ')))	#선분밖의 점
t = ((P[0]-A[0])*(B[0]-A[0]) + (P[1]-A[1])*(B[1]-A[1]) + (P[2]-A[2])*(B[2]-A[2])) / ((B[0]-A[0])**2 + (B[1]-A[1])**2 + (B[2]-A[2])**2)
H = [(B[0]-A[0])*t+A[0], (B[1]-A[1])*t+A[1],(B[2]-A[2])*t+A[2]]	#P와 가장 가까운 선분 위의 점
distance = ((H[0]-P[0])**2 + (H[1]-P[1])**2 + (H[2]-P[2])**2)**0.5
result = int(distance + 1)
f.close()

print(result)

stop = timeit.default_timer()
print("실행시간 : ", stop - start)