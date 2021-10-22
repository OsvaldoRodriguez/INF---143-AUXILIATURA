// https://jv.umsa.bo/problem.php?id=2298 

import sys
 
def criba():
    v[0] = v[1] = 0
    i = 2
    while i * i < N:
        if v[i] == 1:
            for j in range(i * i, N, i):
                v[j] = 0
        i += 1
 
    for i in range(2, N):
        if v[i] == 1:
            pr.append(i)
    for i in range(1, len(pr)):
        pr[i] += pr[i - 1]
 
N = int(1e7 + 5)
v = [1] * N
# guarda los números primos
pr = []    
 
criba()
 
 
t = int(sys.stdin.readline())
 
for _ in range(t):
    x = int(sys.stdin.readline())
 
    a, b, mid = 0, len(pr), 0
 
    while b - a > 1:
        mid = (a + b) >> 1
        if pr[mid] <= x:
            a = mid
        else:
            b = mid
    sys.stdout.write(str(a) + '\n')
